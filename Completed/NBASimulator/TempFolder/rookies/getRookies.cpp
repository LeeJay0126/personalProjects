#include <iostream>
using namespace std;
#include "Rookies.h"
#include <string>
#include <fstream>
#include <iomanip>

void readData(string names[], string fileName);


int main(){
    
    srand (time(nullptr));
    int rookieCount = 0;
    Rookies rookieClass[60];
    int maxPotential = 200 + rand()% (250 - 200 + 1);
    
    string firstNames[100];
    string lastNames[100];
    readData(firstNames, "firstName.csv");
    readData(lastNames, "lastName.csv");

    while (rookieCount <= 59){
        
        int number = rand()%100 + 1;
        rookieClass[rookieCount].setFirstName(firstNames[number]);
        
        number = rand()%100 + 1;
        rookieClass[rookieCount].setLastName(lastNames[number]);
        
        
        int fallOff = rand()% 3 + 1;
        maxPotential = maxPotential - fallOff;
        rookieClass[rookieCount].setPotential(maxPotential);
        
        cout << rookieClass[rookieCount].getFirstName() << " " << rookieClass[rookieCount].getLastName();
        cout << rookieClass[rookieCount].getPotential() << endl;
        
        
        rookieCount ++;
    }
}
void readData(string names[], string fileName){
    
    ifstream input;
    string line;
    input.open(fileName);
    int count = 0;
    
    while (getline(input,line)){
        //cout << line << endl;
        names[count] = line;
        count ++;
    }
    
    input.close();
    
}

