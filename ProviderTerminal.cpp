#include "ProviderTerminal.h"

// TODO Write test suite

ProviderTerminal::ProviderTerminal(DataCenter* dc, ProviderDirectoryHandler* handler) {
	ProviderNum = 0; 
	for (int i = 0; i < 10; ++i)
		MemberNum[i] = 0;
	DC = dc;
	pd_handler_ = handler;
}


int ProviderTerminal::ValidateProvider() {
	
	if (ProviderNum) {
		cout << "Provider " << ProviderNum << " is logged in." << endl;
		return 1;
	}
	
	int input = 0; 
	cout << "Enter provider ID number: ";
	get_digits(input, 9);

	int result = DC->ValidateProvider(input);

	if (result == 1) {
		cout << "VALIDATED" << endl;
		ProviderNum = input;
	} else {
		cout << "INVALID" << endl;
	}

	return result;
}


int ProviderTerminal::CheckProviderNum() {
	if (!ProviderNum) {
		cout << "Permission denied: Provider is not logged in." << endl;
		return ValidateProvider();
	}
	return 1;
}


int ProviderTerminal::ValidateMember() {
	
	if (!CheckProviderNum()) return 0;

	int input = 0; 
	cout << "Enter member ID number: ";
	get_digits(input, 9);

	if (MemberLoggedIn(input) == false) {

		int result = DC->ValidateMember(input);

		if (result == 1) {
			LogMemberIn(input);
			cout << "VALIDATED" << endl; 
		} else if (result == 0) {
			cout << "SUSPENDED" << endl;
		} else { 
			cout << "INVALID" << endl;
		}

	} else {
		return ServiceReport(input);
	}
}


int ProviderTerminal::DirectoryRequest() {
	if (!CheckProviderNum()) return 0;
	//else return DC->DirectoryRequest(ProviderNum);
	pd_handler_ -> Display();
	return 1;
}


int ProviderTerminal::ServiceReport(int IDNum) {
	
	if (!CheckProviderNum()) return 0;
	
	int input = 0;
	int result =  0;
	bool done = false;
	char CDT[len2sz(LEN_TIME)];
	char DoS[len2sz(LEN_DATE)];

	// Populate member and provider numbers.
	Report.MemberNum = IDNum;
	Report.ProviderNum = ProviderNum;

	// Populate current date and time. might not work...
	time_t rawtime;
	struct tm * timestring;
	time(&rawtime);
	timestring = localtime(&rawtime);
	strftime(CDT, len2sz(LEN_TIME), "%m_%d_%Y_%H_%M_%S", timestring);

	strcpy(Report.CDT, CDT);

	// Populate date of service.
 	do {
		cout << "Enter date of service." << endl;
		get_date(DoS);
		cout << "Date of service: " << DoS << endl;
		cout << "Is this correct? (y/n): ";
		if (yes()) done = true;
	} while (!done);
	done = false;

	strcpy(Report.DoS, DoS);

	// Populate service code.
	do {
		//cout << "Enter service code: ";
		//cin >> input;
		//char * ServiceName = DC->validateService(input);
		if ((input = pd_handler_ -> VerifyCode()))
		{
			//cout << "Service name: " << ServiceName << endl;
			cout << "Is this correct? (y/n): ";
				if (yes()) done = true;
		}
	} while (!done);
	done = false;

	Report.ServiceCode = input;
	
	// Populate comments (optional).
	cout << "Would you like to add comments? (y/n): ";
	if (yes()) get_string(Report.Comments, 100);

	// Log out the member.
	LogMemberOut(IDNum);

	result = DC->SavingServiceRecord(Report);
	return result;
}


bool ProviderTerminal::MemberLoggedIn(int IDNum) {
	for (int i = 0; i < 10; ++i) 
		if (MemberNum[i] == IDNum) return true;
	return false;
}

void ProviderTerminal::LogMemberOut(int IDNum) {
	for (int i = 0; i < 10; ++i) {
		if (MemberNum[i] == IDNum) {
			MemberNum[i] = 0;
			return;
		}
	}
}

void ProviderTerminal::LogMemberIn(int IDNum) {
	for (int i = 0; i < 10; ++i) {
		if (MemberNum[i] == 0) {
			MemberNum[i] = IDNum;
			return;
		}
	}
	// Too many members logged in. Overwrite first member.
	MemberNum[0] = IDNum;
}


//Menu for terminal added by Erik Jastad
void ProviderTerminal::menu()
{
	if (!DC || ! pd_handler_)
	{
		cout << "\nProvider Terminal can not start because the Data Center or Provider Directory is unavailable!\n";
		return;
	}

	int Selection = 0;
	char choice;

	while(!Selection)
	{
		cout << "\nProvider Terminal, Please login\n";
		Selection = ValidateProvider();
		if(Selection == 1)
		{
			cout << "\nProvider Terminal\n";
			while(Selection != 3)
			{
				cout << "\nEnter a number selection from the menu"
				     << "\n1) Login/Logout a ChocAn Member"
			     	     << "\n2) Request Provider Directory"
				     << "\n3) Quit"
				     << "\nMenu Choice: ";
			       	get_digits(Selection, 1);

				if(Selection == 1)
				{
					ValidateMember();
				}
				else if (Selection == 2)
				{
					pd_handler_->Display();			
				}

			}
		}	
		else
		{
			cout << "\nTry to Login again? (Y/N)\n"
			       "Selection: ";
			get_up_char(choice);
			if (choice != 'Y')
				Selection = 1;
			else
				Selection = 0;

		}
	}
	ProviderNum = 0;
}
