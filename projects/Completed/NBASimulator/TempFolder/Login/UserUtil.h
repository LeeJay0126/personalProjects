#ifndef USERUTIL_H
#define USERUTIL_H
#include "User.h"
using namespace std;

class UserUtil{
    public:
        string findPw(string id, User *array, int size);
        void upgradeAccess(User user);
        User* addUser(User *users, int size, User user);
        

        
};
#endif