#include <iostream>
#include "Rookies.h"
#include <string>
using namespace std;


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
    this->firstName = tempName;
}

void Rookies::setLastName(string tempName){
    this->lastName = tempName;
}

int Rookies::getPotential(){
    return potential;
}

void Rookies::setPotential(int tempPotential){
    this->potential = tempPotential;
}