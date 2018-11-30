#include "ManagerTerminal.h"

int main()
{
	//Awaiting proper compile
	char sample_tm[] = "11_22_2018_11_13_41";

	FileManager* f = new FileManager();
	f -> Initialize();
	DataCenter* d = new DataCenter(f);
	ProviderDirectoryHandler* handler = new ProviderDirectoryHandler(sample_tm, f);
	ProviderTerminal* pterminal = new ProviderTerminal(d, handler);
	ManagerTerminal* mterminal = new ManagerTerminal(f,d,handler, 3);

	int Selection=0;	//Menu selection variable	
	
	// some code goes here...
	while(Selection!=3)
	{
		cout << "\n\nCHOCAN SIMULATOR\n";
		cout << "Please enter a number selection from the menu below\n"
		     << "1)  Simulate a Provider Terminal.\n"
		     << "2)  Simulate a Managers Terminal.\n"
		     << "3)  Quit\n"
		     << "Menu Choice: ";
		get_digits(Selection, 1);

		if(Selection == 1)
		{
			pterminal->menu();
			Selection = 0;
		}

		if(Selection == 2)
		{
			mterminal->menu();
			Selection = 0;
		}
	}

	delete handler;
	delete d;
	delete f;
	delete pterminal;
	delete mterminal;

	return 0;
}
