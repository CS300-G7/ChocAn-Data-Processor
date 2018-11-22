#include "ProviderTerminal.h"

// TODO Write test suite

ProviderTerminal::ProviderTerminal(DataCenter& DC) {
	ProviderNum = 0; 
	MemberNum = {0}; // maybe change this
	this->DC = DC; 
	ValidateProvider();
}


int ProviderTerminal::ValidateProvider() {
	
	if (ProviderNum) {
		cout << "Provider " + ProviderNum + " is logged in." << endl;
		reutrn 1;
	}
	
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
			cout << "NO SUCH MEMBER" << endl;
		}

	} else {
		return ServiceReport(input);
	}
}


int ProviderTerminal::DirectoryRequest() {
	if (!CheckProviderNum()) return 0;
	else return DC->DirectoryRequest(ProviderNum);
}


int ProviderTerminal::ServiceReport(int IDNum) {
	
	if (!CheckProviderNum()) return 0;
	
	int input = 0;
	int result =  0;
	bool done = false;
	char CDT[19];
	char DoS[19];

	// Populate member and provider numbers.
	Report.MemberNum = IDNum;
	Report.ProviderNum = ProviderNum;

	// Populate current date and time. might not work...
	time_t rawtime;
	struct tm * timestring;
	time(&rawtime);
	timestring = localtime(&rawtime);
	strftime(CDT, 19, "%m-%d-%Y %H:%M:%S", timestring);

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
	// Too many members logged in. Overwrite first member.
	MemberNum[0] = IDNum;
}
