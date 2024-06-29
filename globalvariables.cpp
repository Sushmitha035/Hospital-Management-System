#include "global.h"

char alp[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int num[10] = { 0,1,2,3,4,5,6,7,8,9};
int timearray[] = {9,10,11,12,2,3,4,5} ;
string deptarray[] = {"Opthamology","Orthopaedics","Dental","Cardiology","Radiology","ENT","Neurology","Dermatology","Oncology"} ;


class patient{
    public :
    string name ;
    string appointmentno ;
    string gender ;
    int age ;
    string bloodtype ;
    string department ;
    int appointment_time ;
    string password ;
    bool pwdcreated ;
    string appointeddoc ;

    void admitted(){
        cout<<"Name :"<<endl ;
        cin>>name ;
        cout<<"Gender :"<<endl ;
        cin>>gender;
        cout<<"Age :"<<endl ;
        cin>>age;
        cout<<"Bloodtype :"<<endl ;
        cin>>bloodtype ;
        cout<<"Please create your password"<<endl ;
        cin>>password ;
        pwdcreated = true ;
    }

    void printer(){
        
        cout<<"Patient name : "<<name<<endl ;
        cout<<"Appointment ID : "<<appointmentno<<endl; 
        cout<<"Gender : "<<gender<<endl; 
        cout<<"Age : "<<age<<endl;
        cout<<"Assigned doctor :"<<appointeddoc<<endl ;
        cout<<"Bloodtype: "<<bloodtype<<endl; 
        cout<<"Admitted department : "<<department<<endl; 
       
    }

    void appointmentgenerator(){
        appointmentno = "";
        appointmentno += alp[rand()%26];
        appointmentno += alp[rand()%26];
        appointmentno += char('0' + num[rand()%10]);
        appointmentno += char('0' + num[rand()%10]);
        appointmentno += char('0' + num[rand()%10]);
        appointmentno += char('0' + num[rand()%10]);
    }
        
};

class doctor{

    public :
    string docname ;
    string department ;
    array<bool, 8> appointmentarray = {false,false,false,false,false,false,false,false};

};

vector<doctor> docarray ;
vector<patient> patientarray ;
ifstream docs("Doctorarray.txt");
