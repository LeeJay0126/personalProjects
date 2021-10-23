#include <iostream>
#include "Rookies.h"
#include "RookiesUtil.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void RookiesUtil::recursion(int value, int DraftYear, int pickCount, Rookies rookieClass[]){
    if(pickCount > 59){
        cout << left << setw(15) << "First Name" << setw(15) << "LastName" << setw(10) << "Pick #" << setw(15) << "Draft Year" << setw(10) << "Potential" << endl;
        for(int i = 0; i < pickCount; i++){
            cout << left << setw(15) << rookieClass[i].getFirstName() << setw(15) << rookieClass[i].getLastName() << setw(10) << i << setw(15) << DraftYear << setw(10) << rookieClass[i].getPotential() << endl;
        }
    }else{
        
        int value2 = value - (rand()%(int)(value*0.05));
        int number = rand()%100;
        int number2 = rand()%100;
        string firstName = readData("firstName.csv",number);
        string lastName = readData("lastName.csv",number2);
        
        cout << firstName << endl;
        
        
        rookieClass[pickCount].setFirstName(firstName);
        rookieClass[pickCount].setLastName(lastName);
        rookieClass[pickCount].setPotential(value2);
        
        pickCount++;
        
        recursion(value2,DraftYear,pickCount, rookieClass);
    }
    
}

string RookiesUtil::readData(string fileName, int number){
    
    ifstream input;
    string line;
    input.open(fileName);
    int count = 0;
    
    while(getline(input,line)){
        if(count == number){
            return line;
        }else{
            count++;
        }
    }
    
    return "Invalid number";
    
}