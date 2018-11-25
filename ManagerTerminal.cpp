// line 93, line 177: Data Center DO NOT have 
// related function to support editing user.


#include "ManagerTerminal.h"

ManagerTerminal::ManagerTerminal(FileManager* f,DataCenter* dc, ProviderDirectoryHandler* handler, int ID){
    TerminalID = ID; 
    /*
    person.Name[25] ={0};
    person.IDNumber = 0;
    person.StreetAddress[25] = {0};
    person.City[14] = {0};
    person.State[2] = {0};
    person.ZipCode = 0;
    person.Status = 0;
    */
    //servicecode.Code = 0;
    //servicecode.ServiceName[20] = {0};
    //servicecode.Fee = 0;
    file_manager_ = f;
    DC = dc;
    pd_handler_ = handler;
}

int ManagerTerminal::AddProvider(void){

    cout<<"Name: ";
    get_string(person.Name, 25);

    cout<<"ID Number: ";
    get_digits(person.IDNumber, 9);

    cout<<"Street Address: ";
    get_string(person.StreetAddress,25);

    cout<<"City: ";
    get_string(person.City, 14);

    cout<<"State: ";
    get_string(person.State, 2);

    cout<<"Zip Code: ";
    get_digits(person.ZipCode, 5);

    cout<<"Status: ";
    get_int(person.Status, 0, 2);

    int result = DC->addProvider(person);

    if(result == 1)
        cout<<"Provider added"<<endl;
    else
        cout<<"Provider could not be added"<<endl;
    return result;
}

int ManagerTerminal::AddMember(void){

    cout<<"Name: ";
    get_string(person.Name, 25);

    cout<<"ID Number: ";
    get_digits(person.IDNumber, 9);

    cout<<"Street Address: ";
    get_string(person.StreetAddress,25);

    cout<<"City: ";
    get_string(person.City, 14);

    cout<<"State: ";
    get_string(person.State, 2);

    cout<<"Zip Code: ";
    get_digits(person.ZipCode, 5);

    cout<<"Status: ";
    get_int(person.Status, 0, 2);

    int result = DC->addMember(person);
    if(result ==1)
        cout<<"Member added"<<endl;
    else
        cout<<"Member could not be added"<<endl;
    return result;
}

int ManagerTerminal::AddService(void){
    if(!pd_handler_)
        return false;
    return pd_handler_ -> Insert();
}


// Data Center doesn't have such a function to edit provider
int ManagerTerminal::EditProvider(void){
    
    int choice = 0;
    char response;

    /*
    person.Name[25] ={0};
    person.IDNumber = 0;
    person.StreetAddress[25] = {0};
    person.City[14] = {0};
    person.State[2] = {0};
    person.ZipCode = 0;
    person.Status = 0;
    */
    do{
        cout<<"1: Name"<<endl;
        cout<<"2: ID Number"<<endl;
        cout<<"3: StreetAddress"<<endl;
        cout<<"4: City"<<endl;
        cout<<"5: State"<<endl;
        cout<<"6: Zip Code"<<endl;
        cout<<"7: Status"<<endl;
        
        do{    
            cout<<"What would you like to edit?: ";
            cin>>choice;
            cin.ignore(100, '\n');
        }while(choice<1 || choice>7);

        switch(choice){
             case 1:
                 cout<<"Name: ";
                 get_string(person.Name, 25);
                 break;

            case 2:
                cout<<"ID Number: ";
                get_digits(person.IDNumber, 9);
                break;

            case 3:
                cout<<"Street Address: ";
                get_string(person.StreetAddress,25);
                break;

            case 4:
                cout<<"City: ";
                get_string(person.City, 14);
                break;

            case 5:
                cout<<"State: ";
                get_string(person.State, 2);
                break;

            case 6:
                cout<<"Zip Code: ";
                get_digits(person.ZipCode, 5);
                break;

            case 7:
                cout<<"Status: ";
                get_int(person.Status, 0, 2);
                break;

        }
        cout<<"Would you like to edit something else? Y/N";
        response=yes();
    }while(response=='Y');
    
    /*
    int result = DC->EditProvider(person);
    if(result == 1)
        cout<<"Edit succesful"<<endl;
    else
        cout<<"Edit unsuccesful"<<endl;
    return result;
    */

    return -1;
}


// Data Center doesn't have such a function to edit member
int ManagerTerminal::EditMember(void){
    
    int choice = 0;
    char response;

    /*person.Name[25] ={0};
    person.IDNumber = 0;
    person.StreetAddress[25] = {0};
    person.City[14] = {0};
    person.State[2] = {0};
    person.ZipCode = 0;
    person.Status = 0;
    */
    do{
        cout<<"1: Name"<<endl;
        cout<<"2: ID Number"<<endl;
        cout<<"3: StreetAddress"<<endl;
        cout<<"4: City"<<endl;
        cout<<"5: State"<<endl;
        cout<<"6: Zip Code"<<endl;
        cout<<"7: Status"<<endl;

        do{    
            cout<<"What would you like to edit?: ";
            cin>>choice;
            cin.ignore(100, '\n');
        }while(choice<1 || choice>7);

        switch(choice){
            case 1:
                cout<<"Name: ";
                get_string(person.Name, 25);
                break;

            case 2:
                cout<<"ID Number: ";
                get_digits(person.IDNumber, 9);
                break;

            case 3:
                cout<<"Street Address: ";
                get_string(person.StreetAddress,25);
                break;

            case 4:
                cout<<"City: ";
                get_string(person.City, 14);
                break;

            case 5:
                cout<<"State: ";
                get_string(person.State, 2);
                break;

            case 6:
                cout<<"Zip Code: ";
                get_digits(person.ZipCode, 5);
                break;

            case 7:
                cout<<"Status: ";
                get_int(person.Status, 0, 2);
                break;
        }

        cout<<"Would you like to edit something else? Y/N";
        response=yes();
    }while(response=='Y');
        
    //int result = DC->editMember(person);
    
    /*
    if(result == 1)
        cout<<"Edit succesful"<<endl;
    else
        cout<<"Edit unsuccesful"<<endl;
    return result;
    */

   return -1;
}

int ManagerTerminal::EditService(void){
    return pd_handler_ -> Update();
}

int ManagerTerminal::DeleteProvider(void){

    int idNumber = 0;

    cout<<"ID Number: ";
    get_digits(idNumber, 9);
    
    int result = DC->removeProvider(idNumber);
    if(result == 1)
        cout<<"Provider deleted"<<endl;
    else
        cout<<"Provider could not be deleted"<<endl;
   return result;
}

int ManagerTerminal::DeleteMember(void){

    int idNumber = 0;
    
    cout<<"ID Number: ";
    get_digits(idNumber, 9);

    int result = DC->removeMember(idNumber);
        if(result == 1)
            cout<<"Member deleted"<<endl;
        else
            cout<<"Member could not be deleted"<<endl;
  return result;
}

int ManagerTerminal::DeleteService(void){
    pd_handler_ -> Remove();
}

int ManagerTerminal::ReportMembers(void){
    char dt[len2sz(LEN_TIME)];
    int day_of_week;
    bool ret;

    if(!InputDate(dt))
        return 0;
    day_of_week = InputDayOfWeek();
    ReportGenerator* generator = new ReportGenerator(file_manager_, DC, dt, day_of_week);
    ret = generator -> GenerateMemberReport();
    delete generator;

    return ret;
}

int ManagerTerminal::ReportProviders(void){
    char dt[len2sz(LEN_TIME)];
    int day_of_week;
    bool ret;

    if(!InputDate(dt))
        return 0;
    day_of_week = InputDayOfWeek();
    ReportGenerator* generator = new ReportGenerator(file_manager_, DC, dt, day_of_week);
    ret = generator -> GenerateProviderReport();
    delete generator;

    return ret;
}

int ManagerTerminal::ReportSummary(void){
    char dt[len2sz(LEN_TIME)];
    int day_of_week;
    bool ret;

    if(!InputDate(dt))
        return 0;
    day_of_week = InputDayOfWeek();
    ReportGenerator* generator = new ReportGenerator(file_manager_, DC, dt, day_of_week);
    ret = generator -> GenerateManagerReport();
    delete generator;

    return ret;
}

int ManagerTerminal::ReportEFT(void){
    char dt[len2sz(LEN_TIME)];
    int day_of_week;
    bool ret;

    if(!InputDate(dt))
        return 0;
    day_of_week = InputDayOfWeek();
    ReportGenerator* generator = new ReportGenerator(file_manager_, DC, dt, day_of_week);
    ret = generator -> GenerateEftReport();
    delete generator;

    return ret;
}


bool ManagerTerminal :: InputDate(char* receiver) {
    int m, d, h, min, sec;
    int y = 2018;
    char dt[len2sz(LEN_DATE)];
    bool day_valid = false;

    cout << "Month (1 - 12):" << endl;
    do{
        cin >> m;
        cin.ignore(1000, '\n');
        if(m > 12 || m < 0)
            cout << "Invalid input. The month must between 1 to 12" << endl;
    } while(m > 12 || m < 0);

    cout << "day (1 - 30) or (1 - 31) or (1 - 28)" << endl;
    do{
        cin >> d;
        cin.ignore(1000, '\n');
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if(d <= 0 || d > 31)
                cout << "Invalid input. The day must between 1 to 31" << endl;
            else
                day_valid = true;
        } else if(m == 2) {
            if(d <= 0 || d > 28) 
                cout << "Invalid input. The day must between 1 to 28" << endl;
            else 
                day_valid = true;
        } else {
            if(d <= 0 || d > 30)
                cout << "Invalid input. The day must between 1 to 30" << endl;
            else 
                day_valid = true;
        }
    } while(!day_valid);

    cout << "The year has automatically been set to 2018" << endl;
    Date date(m, d, y);
    date.getch(dt);
    strcpy(receiver, dt);
    return true;
}


int ManagerTerminal :: InputDayOfWeek() {
    int response = 0;
    
    cout << endl;
    cout << "Choose day of week:" << endl;
    cout << "[1] Monday" << endl;
    cout << "[2] Tuesday" << endl;
    cout << "[3] Wednesday" << endl;
    cout << "[4] Thursday" << endl;
    cout << "[5] Friday" << endl;
    cout << "[6] Saturday" << endl;
    cout << "[7] Sunday" << endl;
    
    do{
        cin >> response;
        cin.ignore(1000, '\n');
        if(response <= 0 || response > 7)
            cout << "Enter again. Invalid input." << endl;
    } while(response <= 0 || response > 7);
    
    if(response == 1)
        return MON;
    if(response == 2)
        return TUE;
    if(response == 3)
        return WED;
    if(response == 4)
        return THU;
    if(response == 5)
        return FRI;
    if(response == 6)
        return SAT;
    if(response == 7)
        return SUN;
}
