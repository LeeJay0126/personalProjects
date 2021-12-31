#include "User.h"
#include <string>
using namespace std;

User::User() {
    
}

string User::getId() const{
    return id;
}

string User::getPw() const{
    return pw;
}

string User::getName() const{
    return name;
}

int User::getAccess() const{
    return access;
}

void User::setId(string id){
    this->id = id;
}

void User::setName(string name){
    this->name = name;
}

void User::setPw(string pw){
    this->pw = pw;
}

void User::setAccess(int access){
    this->access = access;
}