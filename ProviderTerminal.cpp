#include "ProviderTerminal.h"

// TODO Write test suite

ProviderTerminal::ProviderTerminal():
	ProviderNum(0) 
{
	MemberNum[10] = {0};
	// DC -> How is the destination for this ptr passed in?
}

int ProviderTerminal::ValidateProvider() {
	
	int input = 0; 
	cout << "Enter provider ID number: ";
	get_digits(input, 9);

	int result = DC->ValidateProvider(input);

	if (result == 1) {
		cout << "VALIDATED" << endl;
		ProviderNum = input;
	} else {
		cout << "NO SUCH PROVIDER" << endl;
	}

	return result;
}

int ProviderTerminal::ValidateMember() {

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
			cout << "NO SUCH MEMBER" << endl;
		}

	} else {
		return ServiceReport(input);
	}
}

bool ProviderTerminal::MemberLoggedIn(int IDNum) {
	for (int i = 0; i < 10; ++i) 
		if (MemberNum[i] == IDNum) return true;
	return false;
}

void ProviderTerminal::LogMemberOut(int IDNum) {
	for (int i = 0; i < 10; ++i) {
		if (MemberNum[i] == IDNum) {
			MemberNum[i] == 0;
			return;
		}
	}
}

void ProviderTerminal::LogMemberIn(int IDNum) {
	for (int i = 0; i < 10; ++i) {
		if (MemberNum[i] == 0) {
			MemberNum[i] == IDNum;
			return;
		}
	}
	// Too many members are logged in, overwrite the first member.
	MemberNum[0] = IDNum;
}

int ProviderTerminal::DirectoryRequest() {
	if (ProviderNum != 0) return DC->DirectoryRequest(ProviderNum);
	else return 0;
}

int ProviderTerminal::ServiceReport(int IDNum) {
	
	int input = 0;
	int result =  0;
	bool done = false;
	char CDT[19];
	char DoS[19];

	// Populate member and provider numbers.
	Report.MemberNum = IDNum;
	Report.ProviderNum = ProviderNum;

	// Populate current date and time. (TODO test this..)
	time_t rawtime;
	struct tm * timestring;
	time(&rawtime);
	timestring = localtime(&rawtime);
	strftime(CDT, 19, "%d-%m-%Y %H:%M:%S", timestring);

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
		cout << "Enter service code: ";
		cin >> input;
		char * ServiceName = DC->ValidateService(input);
		cout << "Service name: " << ServiceName << endl;
		cout << "Is this correct? (y/n): ";
		if (yes()) done = true;
	} while (!done);
	done = false;

	Report.ServiceCode = input;
	
	// Populate comments (optional).
	cout << "Would you like to add comments? (y/n): ";
	if (yes()) get_string(Report.Comments, 100);

	// Log out the member.
	LogMemberOut(IDNum);

	result = DC->SaveServiceReport(Report);
	return result;
}


