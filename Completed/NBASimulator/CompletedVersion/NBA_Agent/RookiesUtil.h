#ifndef ROOKIESUTIL_H
#define ROOKIESUTIL_H
#include "Rookies.h"
using namespace std;

class RookiesUtil{
    
    public:
        void recursion(int value, int DraftYear, int pickCount, Rookies rookieClass[]);
    
    private:
        string readData(string fileName, int number);
    
};

#endif 