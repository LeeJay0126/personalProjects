#ifndef ROOKIES_H
#define ROOKIES_H
using namespace std;

class Rookies {

 public:
  Rookies();
  string getFirstName();
  string getLastName();
  int getPotential();
  void setFirstName(string tempName);
  void setLastName(string tempName);
  void setPotential(int tempPotential);
  

 private:
  string firstName;
  string lastName;
  int potential;
  
  
} ;

#endif 