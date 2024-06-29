#include "globalvariables.cpp"

void loginfailmenu();
void welcomescreen();
void appointment( string name);
void menu();
void gatherdocsinfo();
void createaccount();
void printpatientarray();
void displaydoctors();
void displaydept();
void login_print();
void login();




void gatherdocsinfo(){
int doccount ;
docs>>doccount ;
for( int i = 0 ; i < doccount ; i++){
doctor p ;
docs>>p.docname ; 
docs>>p.department ;
docarray.push_back(p);}
}

void createaccount(){
    patient x ;
    cout<<"Hello ! Enter your details and create an account :"<<endl ;
    x.admitted();
    patientarray.push_back(x) ;
    cout<<"Account succesfully created.\n";
    menu();
}


void printpatientarray(){
    for( auto x : patientarray){
        x.printer();
    }

}

void displaydoctors(int choice){

    cout<<"Here is the list of doctors available for your selected department :\n" ;
    int count = 1 , num ;
    vector<doctor> littledocarray ;
    for( auto i : docarray){
        if (i.department == deptarray[choice]){ cout<<count<<". "<<i.docname<<endl; count++ ; littledocarray.push_back(i); }
    }
    cout<<"Enter the choice :\n";
    cin>>num;
    appointment( littledocarray.at(num - 1).docname);
     
}



void displaydept(){
    cout<<"Enter the department in which you need to book an appointment.\n" ;
    int count = 1,choice ;
    for( auto i : deptarray){
        cout<<count<<". "<<i<<" department"<<endl; 
        count++ ;
    }
    cin>>choice;
    displaydoctors(choice);
}

void login_print(){
    string username ;

        cout<<"Enter your username again :\n";
        cin>>username ;

        int i ;
        for( i = 0 ; i < patientarray.size() ; i++){
        if( !((username == patientarray.at(i).name )) ){ continue; }
        if( username == patientarray.at(i).name){ patientarray.at(i).printer(); break; }
    }
        if(  i == patientarray.size()){ loginfailmenu(); }

        
}


void menu(){

    int choice ;
        cout<<"\n\nHere are the options you are provided with.\n" ;
        cout<<"1. Book an appointment."<<endl ;
        cout<<"2. Review the details you have entered."<<endl ;
        cout<<"3. Logout"<<endl;
        cout<<"Press the corresponding number to look into your  choice :\n" ;
        cin>>choice ;
        switch(choice){
            case 1 :
                displaydept();
                break;

            case 2 :
                login_print();
                break ;
            case 3 :
                cout<<"Logging you out...";
                system("cls");
                welcomescreen();
                break ;
        }

}

void appointment(string name){
    string dude ;
    for( auto x : docarray){
        if( name == x.docname){
            dude = x.department ;
            cout<<"Name of the doctor : "<<name<<endl ;
            cout<<"Here are the time slots of the desired doctor right now : \n";
            for( int i = 0 ; i <= 8 ; i++){
            if( timearray[i] > 5){
                if( x.appointmentarray[i] == false){
                    cout<<i+1<<". "<<timearray[i]<<" a.m. - unfilled slot\n";
                }
                else cout<<i+1<<". "<<timearray[i]<<" a.m. - filled slot\n";
                
            }
            else {
                if( x.appointmentarray[i] == false){
                    cout<<i+1<<". "<<timearray[i]<<" p.m. - unfilled slot\n";
                }
                else cout<<i+1<<". "<<timearray[i]<<" p.m. - filled slot\n";  
            }
            }
        }
    }

    int choice ;
    cout<<"\nNow enter the choice number of slot you desire \n";
    cin>>choice ;
    
    for( auto x : docarray){
        if( name == x.docname){
            x.appointmentarray[choice-1] = true ;
        }
    }
    string username ;
    cout<<"Finally , enter your username once more :\n";
    cin>>username ;
    int i = 0 ;
    for( i = 0 ; i < patientarray.size() ; i++){
        if( patientarray.at(i).name == username){ 
            patientarray.at(i).appointment_time = timearray[choice - 1];
            patientarray.at(i).appointeddoc = name; 
            patientarray.at(i).department = dude ;
            patientarray.at(i).appointmentgenerator();
            cout<<"Appointment successfully created !!\n";
            welcomescreen();
        }
    }
}

void login(){

    system("cls");
    cout<<"Redirecting you to the login menu\n";
    string username , password ;
    cout<<"Enter your username \n";
    cin>>username;
    cout<<"Enter your password\n";
    cin>>password ;

    int i ;
    for( i = 0 ; i < patientarray.size() ; i++){
        if( !((username == patientarray.at(i).name ) && (password == patientarray.at(i).password )) ){ continue; }
        if( username == patientarray.at(i).name && password == patientarray.at(i).password ){ menu(); break; }
    }
        if(  i == patientarray.size()){ loginfailmenu(); }
    
}

void welcomescreen(){
    system("cls");
    cout<<"Redirecting you to welcome window ...\n";
    cout<<"Enter your choice :\n1. To Login\n2. To create an account\n3. To exit \n";
    int k ; 
    cin>>k ;
    switch(k){
        case 1 :{ 
        login(); break;
        }
        case 2 :{
        createaccount() ;    
        break ;
        }
            case 3 :{ abort(); }   
        }
}

void loginfailmenu(){
    cout<<"Username and password don't match.\nPress :\n1. To Login again\n2. To go to welcome screen.\n";
    int choice ; cin>>choice;
    if( choice == 1 ){ login(); }
    else if( choice == 2 ){ welcomescreen(); }
}
