#include "UserUtil.h"
#include "User.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    
    int size = 0;
    UserUtil util;
    
    User *users = new User[size];
    
    int flag = 0;
    string id;
    string pw;
    string name;
    
    while(!(flag == 2)){
        cout << "Enter 1 to add user, 2 to exit" << endl;
        cin >> flag;
        if(flag == 1){
            
            size ++;
            cout << "Enter your name" << endl;
            cin >> name;
            cout << "Enter ID" << endl;
            cin >> id;
            cout << "Enter password" << endl;
            cin >> pw;
            
            User temp;
            temp.setId(id);
            temp.setPw(pw);
            temp.setName(name);
            
            users = util.addUser(users,size,temp);
            cout << size;
            cout << users[0].getId() << setw(10) << users[0].getPw() << endl;
        }
    }
    
    flag = 1;
    while(!(flag == 2)){
        
        cout << "Finding Password Tester. Enter 1 to find and 2 to end" << endl;
        cin >> flag;
        
        if(flag == 1){
            cout << "Enter your Id: " << endl;
            cin >> id;
        
            pw = util.findPw(id,users,size);
            cout << pw << endl;
        }
    }
    
    for(int i = 0; i < size; i++){
        cout << left <<setw(10) << users[i].getId() << setw(10) << users[i].getPw() << endl; 
    }
    
}