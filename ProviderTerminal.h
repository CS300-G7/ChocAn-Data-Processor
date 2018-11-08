#include "structs.h"
#include "scanner.h"
#include <ctime>

class ProviderTerminal {

	public:

		ProviderTerminal();

		int ValidateMember();	
		int ValidateProvider();	
		int DirectoryRequest();	

	private:

		int ServiceReport(int);	
		void LogMemberIn(int);
		void LogMemberOut(int);
		bool MemberLoggedIn(int);

		int ProviderNum;
		int * MemberNum;	
		struct ServiceReport Report;
		DataCenter * DC;	
};



