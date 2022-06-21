#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

    class User{
        public:
            User();
            string getId() const;
            string getPw() const;
            string getName() const;
            int getAccess() const;
            void setAccess(int access);
            void setId(string id);
            void setPw(string pw);
            void setName(string name);
            string findPw(string id);
        
        private:
            string id;
            string pw;
            string name;
            int access = 1;
        
    };
    #endif