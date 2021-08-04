#include <iostream>
using namespace std;
#include "Rookies.h"
#include <string>

Rookies::Rookies(){
  string firstName = "";
  string lastName = "";
  int potential = 0;
}


string Rookies::getFirstName(){
    return firstName;
}

string Rookies::getLastName(){
    return lastName;
}

void Rookies::setFirstName(string tempName){
    firstName = tempName;
}

void Rookies::setLastName(string tempName){
    lastName = tempName;
}

int Rookies::getPotential(){
    return potential;
}

void Rookies::setPotential(int tempPotential){
    potential = tempPotential;
}