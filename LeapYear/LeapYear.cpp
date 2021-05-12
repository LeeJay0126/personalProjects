#include <iostream>
using namespace std;
string leapCalculator(int);

int main(){
   
    cout << "Enter the year: ";
    int year;
    cin >> year;

    string result = leapCalculator(year);

    cout << result;

}

string leapCalculator(int year){
    if(year % 4 == 0){
        if(year%100 == 0){
            if(year%400 == 0){
                return "This year is a leap year.";
            }else{
                return "This year is not a leap year.";
            }
        }else{
            return "This year is a leap year.";
        }
    }else{
        return "This year is not a leap year.";
    }
}