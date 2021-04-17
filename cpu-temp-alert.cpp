/************************************************
 * code to collect system cpu tempreture info
 * from /proc/acpi or /sys files and sends a alarm
 * in case tempreture gets higher than threshold
 *  
 * current threshold = 75
 * 
 * 
 * 
 * 17-April-2021
 * ************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    ifstream file_handle ("/proc/acpi/ibm/thermal");
    string line;
    if(file_handle.is_open()){
        
        while(getline(file_handle,line)){
            cout<<"tempreture stanza is found"<<endl;
            cout<<line<<endl;
            line = line.substr(14,2);
            break;
        }
    
    }else{
        cout<<"unable to collect tempreture info.."<<endl;
    }
    file_handle.close();
    int temp= stoi(line);
    cout<<"tempreture = " << temp<<endl;
    if(temp > 50){
        //send alarm
        cout<<"sending alarm....";
        cout<<'\a';
        //TO_DO
        //add notifications with lib-notification
    }
    
    return 0;
}
