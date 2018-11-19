#include "ManagerTerminal.h"

int ManagerTerminal::AddProvider(void){

    cout<<"Name: ";
    cin.get(person.Name, 25, '\n');
    cin.ignore(100, '\n');

    cout<<"ID Number: ";
    cin>>person.IDNumber;
    cin.ignore(100, '\n');

    cout<<"Street Address: ";
    cin.get(person.StreetAddress, 25, '\n');
    cin.ignore(100, '\n');

    cout<<"City: ";
    cin.get(person.City, 14, '\n');
    cin.ignore(100, '\n');

    cout<<"State: ";
    cin.get(person.State, 2, '\n');
    cin.ignore(100, '\n');

    cout<<"Zip Code: ";
    cin>>person.ZipCode;
    cin.ignore(100, '\n');

    cout<<"Status: ";
    cin>>person.Status;
    cin.ignore(100, '\n');

    int result = DC->AddProvider(person);
    if(result ==1)
        cout<<"Provider added"<<endl;
    else
        cout<<"Provider could not be added"<<endl;
    return result;
}

int ManagerTerminal::AddMember(void){

    cout<<"Name: ";
    cin.get(person.Name, 25, '\n');
    cin.ignore(100, '\n');

    cout<<"ID Number: ";
    cin>>person.IDNumber;
    cin.ignore(100, '\n');

    cout<<"Street Address: ";
    cin.get(person.StreetAddress, 25, '\n');
    cin.ignore(100, '\n');

    cout<<"City: ";
    cin.get(person.City, 14, '\n');
    cin.ignore(100, '\n');

    cout<<"State: ";
    cin.get(person.State, 2, '\n');
    cin.ignore(100, '\n');

    cout<<"Zip Code: ";
    cin>>person.ZipCode;
    cin.ignore(100, '\n');

    cout<<"Status: ";
    cin>>person.Status;
    cin.ignore(100, '\n');

    int result = DC->AddMember(person);
    if(result ==1)
        cout<<"Member added"<<endl;
    else
        cout<<"Member could not be added"<<endl;
    return result;
}

int ManagerTerminal::AddService(void){

    cout<<"Service Code: ";
    cin>>servicecode.Code;
    cin.ignore(100, '\n');

    cout<<"ServiceName: ";
    cin.get(servicecode.ServiceName, 20, '\n');
    cin.ignore(100, '\n');

    cout<<"Fee: ";
    cin>>servicecode.Fee;
    cin.ignore(100, '\n');

    int result = DC->AddService(servicecode);
    if(result == 1)
        cout<<"Service added"<<endl;
    else
        cout<<"Service could not be added"<<endl;
    return result;
}

int ManagerTerminal::EditProvider(void){
    
    int choice = 0;
    char response;

    person.Name[25] ={0};
    person.IDNumber = 0;
    person.StreetAddress[25] = {0};
    person.City[14] = {0};
    person.State[2] = {0};
    person.ZipCode = 0;
    person.Status = 0;

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
                cin.get(person.Name, 25, '\n');
                cin.ignore(100, '\n');
                break;

            case 2:
                cout<<"ID Number: ";
                cin>>person.IDNumber;
                cin.ignore(100, '\n');
                break;

            case 3:
                cout<<"Street Address: ";
                cin.get(person.StreetAddress, 25, '\n');
                cin.ignore(100, '\n');
                break;

            case 4:
                cout<<"City: ";
                cin.get(person.City, 14, '\n');
                cin.ignore(100, '\n');
                break;

            case 5:
                cout<<"State: ";
                cin.get(person.State, 2, '\n');
                cin.ignore(100, '\n');
                break;

            case 6:
                cout<<"Zip Code: ";
                cin>>person.ZipCode;
                cin.ignore(100, '\n');
                break;

            case 7:
                cout<<"Status: ";
                cin>>person.Status;
                cin.ignore(100, '\n');
                break;

        }
        cout<<"Would you like to edit something else? Y/N";
        cin>>response;
    }while(response=='Y');
    
    int result = DC->EditProvider(person);
    if(result == 1)
        cout<<"Edit succesful"<<endl;
    else
        cout<<"Edit unsuccesful"<<endl;
    return result;

}

int ManagerTerminal::EditMember(void){
    
    int choice = 0;
    char response;

    person.Name[25] ={0};
    person.IDNumber = 0;
    person.StreetAddress[25] = {0};
    person.City[14] = {0};
    person.State[2] = {0};
    person.ZipCode = 0;
    person.Status = 0;

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
                cin.get(person.Name, 25, '\n');
                cin.ignore(100, '\n');
                break;

            case 2:
                cout<<"ID Number: ";
                cin>>person.IDNumber;
                cin.ignore(100, '\n');
                break;

            case 3:
                cout<<"Street Address: ";
                cin.get(person.StreetAddress, 25, '\n');
                cin.ignore(100, '\n');
                break;

            case 4:
                cout<<"City: ";
                cin.get(person.City, 14, '\n');
                cin.ignore(100, '\n');
                break;

            case 5:
                cout<<"State: ";
                cin.get(person.State, 2, '\n');
                cin.ignore(100, '\n');
                break;

            case 6:
                cout<<"Zip Code: ";
                cin>>person.ZipCode;
                cin.ignore(100, '\n');
                break;

            case 7:
                cout<<"Status: ";
                cin>>person.Status;
                cin.ignore(100, '\n');
                break;
        }

        cout<<"Would you like to edit something else? Y/N";
        cin>>response;
    }while(response=='Y');
        
    int result = DC->EditMember(person);
    if(result == 1)
        cout<<"Edit succesful"<<endl;
    else
        cout<<"Edit unsuccesful"<<endl;
    return result;

}
int ManagerTerminal::EditService(void){
 
    int choice = 0;
    char response;

    servicecode.Code = 0;
    servicecode.ServiceName[20] = {0};
    servicecode.Fee = 0;
    do{
        cout<<"1: Service Code"<<endl;
        cout<<"2: Service Name"<<endl;
        cout<<"3: Service Fee"<<endl;
    
        do{    
            cout<<"What would you like to edit?: ";
            cin>>choice;
            cin.ignore(100, '\n');
        }while(choice<1 || choice>3);

        switch(choice){
           case 1:
                cout<<"Service Code: ";
                cin>>servicecode.Code;
                cin.ignore(100, '\n');
                break;

            case 2:
                cout<<"Service Name: ";
                cin.get(servicecode.ServiceName, 20, '\n');
                cin.ignore(100, '\n');
                break;

            case 3:
                cout<<"Fee: ";
                cin>>servicecode.Fee;
                cin.ignore(100, '\n');
                break;
            }

        cout<<"Would you like to edit something else? Y/N";
        cin>>response;
    }while(response=='Y');
    
    int result = DC->EditService(servicecode);
    if(result == 1)
        cout<<"Edit succesful"<<endl;
    else
        cout<<"Edit unsuccesful"<<endl;
    return result;
            
}

int ManagerTerminal::DeleteProvider(void){

    int idNumber = 0;

    cout<<"ID Number: ";
    cin>>idNumber;
    cin.ignore(100, '\n');
    
    int result = DC->DeleteProvider(idNumber);
    if(result == 1)
        cout<<"Provider deleted"<<endl;
    else
        cout<<"Provider could not be deleted"<<endl;
   return result;
}

int ManagerTerminal::DeleteMember(void){

    int idNumber = 0;
    
    cout<<"ID Number: ";
    cin>>idNumber;
    cin.ignore(100, '\n');

    int result = DC->DeleteMember(idNumber);
        if(result == 1)
            cout<<"Member deleted"<<endl;
        else
            cout<<"Member could not be deleted"<<endl;
  return result;
}

int ManagerTerminal::DeleteService(void){
    
    int code = 0;

    cout<<"Service Code: ";
    cin>>code;
    cin.ignore(100, '\n');

    int result = DC->DeleteService(code);
    if(result == 1)
        cout<<"Service deleted"<<endl;
    else
        cout<<"Service could not be deleted"<<endl;
 return result;
}

int ManagerTerminal::ReportMembers(void){

    char date[12];
    int terminalID = 0;

    cout<<"Date: ";
    cin.get(date,12,'\n');
    cin.ignore(12);

    cout<<"Terminal ID: ";
    cin>>terminalID;
    cin.ignore(100, '\n');

    int result = ReportMembers(date, terminalID);
    return result;
}

int ManagerTerminal::ReportProviders(void){

    char date[13];
    int terminalID = 0;

    cout<<"Date: ";
    cin.get(date,13,'\n');
    cin.ignore(12);

    cout<<"Terminal ID: ";
    cin>>terminalID;
    cin.ignore(100, '\n');

    int result = ReportProviders(date, terminalID);
    return result;
}

int ManagerTerminal::ReportSummary(void){

    char date[13];
    int terminalID = 0;

    cout<<"Date: ";
    cin.get(date,13,'\n');
    cin.ignore(12);

    cout<<"Terminal ID: ";
    cin>>terminalID;
    cin.ignore(100, '\n');

    int result = ReportSummary(date, terminalID);
    return result;
}

int ManagerTerminal::ReportEFT(void){

    char date[13];
    int terminalID = 0;

    cout<<"Date: ";
    cin.get(date,13,'\n');
    cin.ignore(12);

    cout<<"Terminal ID: ";
    cin>>terminalID;
    cin.ignore(100, '\n');

    int result = ReportEFT(date, terminalID);
    return result;
}

