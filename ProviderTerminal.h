#include "scanner.h"
#include <ctime>
#include "pd:rp.h"

class ProviderTerminal {

	public:

		ProviderTerminal(DataCenter*, ProviderDirectoryHandler*);

		int ValidateMember();	
		int ValidateProvider();	
		int DirectoryRequest();	
		void menu();

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
		ProviderDirectoryHandler* pd_handler_;	
};



