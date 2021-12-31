#include "User.h"
#include "UserUtil.h"
#include <string>
using namespace std;

string UserUtil::findPw(string id, User *array,int size){
    for(int i = 0; i < size; i++){
        if(array[i].getId() == id){
            return "Your Password is : " + array[i].getPw();
        }
    }
    return "Invalid ID. Check your Id again.";
}

void UserUtil::upgradeAccess(User user){

    user.setAccess(2);
    
}

User* UserUtil::addUser(User *users, int size, User user){
    
    User *temp = new User[size];
    
    for(int i = 0; i < size-1; i++){
        temp[i] = users[i];
    }
    
    temp[size-1] = user;
    
    delete[] users;
    return temp;
    
    
}

User UserUtil::logIn(User* users, string id, string password, int size){
    
    for(int i = 0; i < size; i++){
        if(id == users[i].getId()){
            if(password == users[i].getPw()){
                return users[i];
            }
        }
    }
    
    User nullUser;
    nullUser.setName("nullUser");
    
    return nullUser;
}

