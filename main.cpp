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
	char choice;	
	
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
			Selection = 0;
			while(!Selection)
			{
				cout << "\nProvider Terminal Selected, Please login\n";
				Selection = pterminal->ValidateProvider();
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
							pterminal->ValidateMember();
						}
						else if (Selection == 2)
						{
							handler->Display();			
						}

					}
					delete pterminal;
					pterminal = new ProviderTerminal(d, handler);
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
			Selection = 0;
		
		}




		if(Selection == 2)
		{
			Selection = 0;	
			cout << "\nManager Terminal Selected";
			cout << "\nManager Terminal\n";
			while(Selection != 10)
			{
				Selection = 0;
				/*cout << "\nEnter a number selection from the menu"
				     << "\n1 ) Add a ChocAn Member"
			     	 << "\n2 ) Add a ChocAn Provider"
				     << "\n3 ) Add a ChocAn Service"
				     << "\n4 ) Edit a ChocAn Member"
				     << "\n5 ) Edit a ChocAn Provider"
				     << "\n6 ) Edit a ChocAn Service"
				     << "\n7 ) Delete a ChocAn Member"
				     << "\n8 ) Delete a ChocAn Provider"
				     << "\n9 ) Delete a ChocAn Service"
				     << "\n10) Quit"
				     << "\nMenu Choice: ";
				*/
				d -> ManagerInterface();
				cout << "Enter the number from the menu (1 - 9), Press 10 to exit." << endl;
				while(!Selection)
				{
					cin >> Selection;

				       	if (!cin)
					{
						cout << "Invalid entry. Enter a number from the menu";
						Selection = 0;
						cin.clear();
						cin.ignore(1000,'\n');
					}
					cin.ignore(1000,'\n');
				} 

				if(Selection == 1)
				{
					mterminal->AddMember();
				}
				else if (Selection == 2)
				{
					mterminal->AddProvider();
				}
				else if (Selection == 3)
				{
					handler -> Display();
					mterminal->AddService();
				}
				else if(Selection == 4)
				{
					mterminal->EditMember();
				}
				else if(Selection == 5)
				{
					mterminal->EditProvider();
				}
				else if(Selection == 6)
				{
					mterminal->EditService();
				}
				else if(Selection == 7)
				{
					mterminal->DeleteMember();
				}
				else if(Selection == 8)
				{
					mterminal->DeleteProvider();
				}
				else if(Selection == 9)
				{
					mterminal->DeleteService();
				}
			}

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
