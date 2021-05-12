#include <iostream>
#include <iomanip>
using namespace std;
int daysInMonth(int, int);
int LeapYearTester(int);
string getMonthName(int);

int main()
{
    //main method
    int year, day, startDate, leap;
    string month;

    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the start day of the year: ";
    cin >> startDate;

    int firstDay = 0;
    leap = LeapYearTester(year);

    int dayCount = 0;
    int doe = 0;

    for (int i = 1; i < 13; i++)
    {

        day = daysInMonth(i, leap);
        month = getMonthName(i);

        dayCount = 0;

        if (i > 1)
        {
            firstDay = ((firstDay + doe) % 7);
        }
        else if(i==1)
        {
            firstDay = startDate-1;
        }

        doe = day;
        cout << month << endl;
        cout << endl;
        cout << fixed << left << setw(10) << "Monday" << fixed << left << setw(10) << "Tuesday" << fixed << left << setw(10) << "Wednesday" << fixed << left << setw(10) << "Thursday" << fixed << left << setw(10) << "Friday" << fixed << left << setw(10) << "Saturday" << fixed << left << setw(10) << "Sunday" << endl;
        cout << "______________________________________________________________________________" << endl;
        for (int p = 0; p < firstDay; p++)
        {
            cout << setw(10) << "";
            dayCount++;
        }
        for (int j = 0; j < day; j++)
        {
            if (dayCount % 7 == 0)
            {
                cout << endl;
            }
            cout << fixed << left << setw(10) << j + 1;
            dayCount++;
        }

        cout << endl;
        cout << endl;
        cout << firstDay;
    }
}

int LeapYearTester(int year)
{

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int daysInMonth(int month, int leap)
{
    switch (month)
    {
    case 1:
        return 31;
        break;
    case 2:
        if (leap == 0)
        {
            return 28;
            break;
        }
        else
        {
            return 29;
            break;
        }
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    default:
        return 0;
        break;
    }
}

string getMonthName(int month)
{
    switch (month)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "No";
        break;
    }
}