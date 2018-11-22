#include "ManagerTerminal.h"

ManagerTerminal::ManagerTerminal(DataCenter& DC){
    TerminalID = 0; 

    person.Name[25] ={0};
    person.IDNumber = 0;
    person.StreetAddress[25] = {0};
    person.City[14] = {0};
    person.State[2] = {0};
    person.ZipCode = 0;
    person.Status = 0;

    servicecode.Code = 0;
    servicecode.ServiceName[20] = {0};
    servicecode.Fee = 0;

    this->DC = DC;
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

    int result = DC->AddProvider(person);

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

    int result = DC->AddMember(person);
    if(result ==1)
        cout<<"Member added"<<endl;
    else
        cout<<"Member could not be added"<<endl;
    return result;
}

int ManagerTerminal::AddService(void){

    float var =0;
    bool failed = true;

    cout<<"Service Code: ";
    get_int(servicecode.Code, 6);

    cout<<"ServiceName: ";
    get_string(servicecode.ServiceName, 20);

    do{
        cout<<"Fee: ";
        cin>>var;
        cin.ignore(100,'\n');
        failed = cin.fail();
        if(failed){
            cin.clear();
            cin.ignore(100,'\n');
        }
    }while(failed || var >=999.99);
    float value = (int)(var*100 + .5);
    servicecode.Fee = value/100;

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
                get_int(servicecode.Code, 6);
                break;

            case 2:
                cout<<"Service Name: ";
                get_string(servicecode.ServiceName, 20);
                break;

            case 3:
                do{
                    cout<<"Fee: ";
                    cin>>var;
                    cin.ignore(100,'\n');
                    failed = cin.fail();
                    if(failed){
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                }while(failed || var>=999.99);
                float value = (int)(var*100 + .5);
                servicecode.Fee = value/100;
                break;
         }

        cout<<"Would you like to edit something else? Y/N";
        response=yes();
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
    get_digits(idNumber, 9);
    
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
    get_digits(idNumber, 9);

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
    get_digits(code, 6);

    int result = DC->DeleteService(code);
    if(result == 1)
        cout<<"Service deleted"<<endl;
    else
        cout<<"Service could not be deleted"<<endl;
 return result;
}

int ManagerTerminal::ReportMembers(void){

    char date[19];
    int terminalID = 0;

    cout<<"Date: ";
    get_date(date);

    cout<<"Terminal ID: ";
    get_pos_int(terminalID);

    int result = DC->ReportMembers(date, terminalID);
    return result;
}

int ManagerTerminal::ReportProviders(void){

    char date[19];
    int terminalID = 0;

    cout<<"Date: ";
    get_date(date);

    cout<<"Terminal ID: ";
    get_pos_int(terminalID);

    int result = DC->ReportProviders(date, terminalID);
    return result;
}

int ManagerTerminal::ReportSummary(void){

    char date[19];
    int terminalID = 0;

    cout<<"Date: ";
    get_date(date);

    cout<<"Terminal ID: ";
    get_pos_int(terminalID);

    int result = DC->ReportSummary(date, terminalID);
    return result;
}

int ManagerTerminal::ReportEFT(void){

    char date[13];
    int terminalID = 0;

    cout<<"Date: ";
    get_date(date);

    cout<<"Terminal ID: ";
    get_pos_int(terminalID);

    int result = DC->ReportEFT(date, terminalID);
    return result;
}

