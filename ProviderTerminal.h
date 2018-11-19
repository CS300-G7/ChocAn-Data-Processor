#include "structs.h"
#include "scanner.h"
#include <ctime>

class ProviderTerminal {

	public:

		ProviderTerminal(DataCenter&);

		int ValidateMember();	
		int ValidateProvider();	
		int DirectoryRequest();	

	private:

		int ServiceReport(int);	
		void LogMemberIn(int);
		void LogMemberOut(int);
		bool MemberLoggedIn(int);
		int CheckProviderNum();

		int ProviderNum;
		int MemberNum[10];	
		struct ServiceReport Report;
		DataCenter* DC;	
};



