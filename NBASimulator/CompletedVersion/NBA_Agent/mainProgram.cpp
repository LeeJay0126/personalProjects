#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "User.h"
#include "UserUtil.h"
#include "Player.h"
#include "PlayerUtil.cpp"
#include "Node.h"
#include "Rookies.h"
#include "RookiesUtil.h"
using namespace std;

User mainMenu();
int secondMenu(User LoggedIn);
void adminCSV(string csvName, int userSize, User* users);
void PremiumAccess(int secondLoginInt);
void userInformation();
User * newUserList(User modifyUser, User * users,int userSize, int userNumber);
User currentUser;
User *users;
int userSize;
User admin;

int main(){
    
    User LoggedIn = mainMenu();
    int secondLoginInt = secondMenu(LoggedIn);
    
    PremiumAccess(secondLoginInt);

    
}

void PremiumAccess(int secondLoginInt){
    
    Node<Player> *head = nullptr;
    string header[21];
    readFile(&head,"NbaPlayers.csv",header);
    
    RookiesUtil rookieUtil;
    Rookies rookieClass[60];
    int draftYear = 0;
    
    int entry = 0;

    if(secondLoginInt == 1){
        while(!(entry == 3)){
            cout << "Following options are available in regular ID access level" << endl;
            cout << "Enter 1 to view stats of the player, 2 to view them in ascending order (player rank) and 3 to exit the program" << endl;
            cin >> entry;
            if(entry == 1){
                cout << "Would you like to see players' stats or awards? Enter 1 for stats 2 for awards" << endl;
                cin >> entry;
                
                if(entry == 1){
                    displayStats(head,header);
                }else if(entry == 2){
                    displayAwards(head,header);
                }else if(entry == 3){
                    cout << "Thank you for visiting!" << endl;
                }else{
                    cout << "invalid entry! Try again!" << endl;
                }
                
            }else if(entry == 2){
                
                displayPlayerRank(head);
                
                
            }else if( entry == 3){
                cout << "Thank you for visiting!" << endl;
            }else{
                cout << "Invalid entry! Try again!" << endl;
            }
        }
    }else if(secondLoginInt == 2){
        while(!(entry == 4)){
            cout << "Welcome, you have premium level access for this account" << endl;
            cout << "Following are the available options for Premium users " << endl;
            cout << "Enter 1 for Scout evaluation, 2 for Trade simulator, 3 for Rookie Draft, 4 to exit the program" << endl;
            cin >> entry;
            if(entry == 1){
                cout << "Enter 1 to view players' stats, 2 to view their awards, and 3 to display players with their playerworth" << endl;
                cin >> entry;
                if(entry == 1){
                    displayStats(head,header);
                }else if(entry == 2){
                    displayAwards(head, header);
                }else if(entry == 3){
                    display(head, header);
                }else if(entry == 4){
                    cout << "Thank you for visiting!" << endl;
                }else{
                    cout << "Invalid entry! Try again!" << endl;
                }
            }else if(entry == 2){
                assignTeams(head);
            }else if(entry == 3){
                
                cout << "Enter a Draft Year you want to participate in (After 2021 and before 2028) : " << endl;
                cin >> draftYear ;
                
                if(draftYear >= 2021 && draftYear <= 2028){
                    rookieUtil.recursion(300,draftYear,0,rookieClass);
                }else{
                    cout << "Enter a year after 2021 and before 2028! " << endl;
                }
                
            }else if(entry == 4){
                cout << "Thank you for Visiting!" << endl;
            }else{
                cout << "Invalid entry! Try again!" << endl;
            }
        }
    
    }else if(secondLoginInt == 3){
     
        string access = "";
        string csvName = "";
        entry = 1;
        
        while(!(entry == 3)){
            cout << "You are logged in as an admin" << endl;
            cout << "Enter 1 for User Report, 2 for Modifying user information, 3 to exit the program" << endl;
            cin >> entry;
            if(entry == 1){

                userInformation();
                
                cout << "Would you like to store this information to a csv file?" << endl;
                cout << "Enter 1 if yes, 2 if not, and 3 if you want to exit. : ";
                cin >> entry;
                
                if(entry == 1){
                    
                    cout << "Enter the csv file name you would like to save this information as : " ;
                    cin >> csvName;
                    
                    adminCSV(csvName,userSize,users);
                    
                }else{
                    cout << "Thank you! See you again!" << endl;
                }
                
            }else if(entry == 2){
                
                string modifyId = "";
                User modifyUser;
                int modifyCount = 0;
                string modId = "";
                string modPw = "";
                string modName = "";
                int modAccess = 0;
                int userNumber = 0;
                
                while(!(modifyCount == 5)){
                    
                    userInformation();
                    cout << "Enter the ID of the user you want to modify the information on" << endl;
                    cin >> modifyId;
                
                    for(int i = 0; i < userSize; i++){
                        if(users[i].getId() == modifyId){
                            modifyUser = users[i];
                            modifyCount++;
                            userNumber = i;
                        }
                    }
                    
                    if(modifyCount >= 1){
                        cout << "Enter 1 to modify user name, 2 for user access level, 3 for Id, 4 for password, and 5 to exit the program. You can grant admin level access level to other users. : " << endl;
                        cin >> modifyCount;
                        if(modifyCount == 1){
                            cout << "To what name do you want to change this user's name? :" ;
                            cin >> modName;
                            modifyUser.setName(modName);
                        }else if(modifyCount == 2){
                            cout << "To what Access level do you want to change this user's access level? : ";
                            cin >> modAccess;
                            modifyUser.setAccess(modAccess);
                        }else if(modifyCount == 3){
                            cout << "To what Id do you want to change this user's id? : ";
                            cin >> modId;
                            modifyUser.setId(modId);
                        }else if(modifyCount == 4){
                            cout << "To what password do you want to change this user's password? : ";
                            cin >> modPw;
                            modifyUser.setPw(modPw);
                        }
                    }
                    
                    users = newUserList(modifyUser, users, userSize, userNumber);
                    
                    cout <<"Enter 5 to quit, any other integer to continue modify user information" << endl;
                    cin >> modifyCount;
                    
                }
                
                
            }
        }
    }else if(secondLoginInt == 4){
     
        cout <<"Thank you for visiting!" << endl;
    
        
    }else{
            
        cout << "Invalid Entry! Try again!" << endl;
        
    }
    
}

User * newUserList(User modifyUser, User * users,int userSize, int userNumber){
    
    User * temp = new User [userSize];
    
    for(int i = 0; i < userSize; i++){
        temp[i].setId(users[i].getId());
        temp[i].setName(users[i].getName());
        temp[i].setPw(users[i].getPw());
        temp[i].setAccess(users[i].getAccess());
    }
    
    temp[userNumber].setId(modifyUser.getId());
    temp[userNumber].setPw(modifyUser.getPw());
    temp[userNumber].setAccess(modifyUser.getAccess());
    temp[userNumber].setName(modifyUser.getName());
    delete[] users;
    return temp;
    
    
}

void userInformation(){
              
    string access = "";
                    
    for(int i = 0; i < userSize; i++){
                    
        if(users[i].getAccess() == 1){
            access = "Regular";
        }else if(users[i].getAccess() == 2){
            access = "Premium";
        }else{
            access = "Admin";
        }
        
        cout << left << "Name: "<< setw(20) << users[i].getName() << " Access: " << setw(10) << users[i].getAccess() << " ID: " << setw(15) << users[i].getId() << " Password: " << setw(15) << users[i].getPw() << endl;
    }
}

void adminCSV(string csvName, int userSize, User* users){
    
    ofstream output;
    output.open(csvName);
    int count = 0;
    
    output << "Name, Access, ID, PassWord \n";
    
    string access = "";
    
    while(count < userSize){
        
        if(users[count].getAccess() == 1){
            access = "Regular";
        }else if(users[count].getAccess() == 2){
            access = "Premium";
        }else{
            access = "Admin";
        }
        
        output << users[count].getName() + "," + access + "," + users[count].getId() + "," + users[count].getPw() + "\n";
        
        count ++;
    }
    
}

int secondMenu(User LoggedIn){
    
    int flag = 0;
    int accessFlag = 0;
    string accessLevel = "";
    
    if(LoggedIn.getAccess() == 3){
        cout << "You are logged in as an admin." << endl;
        return 3;
    }
    else{
        cout << "Regular ID and Premium ID has different features. Would you like to upgrade your access level?" << endl;
        cout << "Enter 1 if yes, 2 if no" << endl;
        cin >> accessFlag;
    
        if(accessFlag == 1){
            if(LoggedIn.getAccess() == 1){
                LoggedIn.setAccess(2);
                cout << "You access is now Premium" << endl;
            }else{
                cout << "You can only upgrade your access level when your access level is Regular ID" << endl;
            }
        }else{
            cout << "Logging in to your account!" << endl;
        }
    
        if(LoggedIn.getAccess() == 1){
            cout << "Your access level is Regular ID" << endl;
            return 1;
            
        }else{
            cout << "Your access level is Premium ID" << endl;
            return 2;
        }
    }
    
}


User mainMenu(){
    
    int main1 = 0;
    string userID = "";
    string userPW = "";
    userSize = 0;
    string name;
    int flag;
    string result;
    
    UserUtil userUtil;
    
    //Creating admin account. It's information is pre-set.
    admin.setName("Admin");
    admin.setId("NBAadmin");
    admin.setPw("NBA123");
    admin.setAccess(3);
    
    cout << "Welcome to NBA Agent" << endl;
    
    users = new User[userSize];
    userSize ++;
    users = userUtil.addUser(users,userSize,admin);
    
    while(!(main1 == 3)){
         
         cout << "If you have an account with us, enter 1. If not, Enter 2. Enter 3 to Exit." <<endl;
         cin >> main1;
         
         if(main1 == 1){
            if(userSize > 1){
                
                cout << "Enter your ID" << endl;
                cin >> userID;
                cout << "Enter your Password" << endl;
                cin >> userPW;
             
                currentUser = userUtil.logIn(users,userID,userPW,userSize);
            
                if(currentUser.getName() == "nullUser"){
                    flag = 0;
                    cout << "Wrong ID or password! " << endl;
                    cout << "Enter 1 if you forgot your password: " << endl;
                    cin >> flag;
                    
                    if(flag == 1){
                        cout << "Enter your ID" << endl;
                        cin >> userID;
                        result = userUtil.findPw(userID, users, userSize);
                        cout << result << endl;
                    }
                    
                }else{
                    cout << "Logged in!" << endl;
                    cout << "You are logged in as ID: " << currentUser.getId() << endl;
                    return currentUser;
                    main1 = 3;
                }
            }else{
                cout << "Currently no users are registered." << endl;
            }
            
         }else if(main1 == 2){
            
            userSize++;
            cout << "Enter your name: " << endl;
            cin >> name;
            cout << "Enter your ID" << endl;
            cin >> userID;
            cout << "Enter your Password" << endl;
            cin >> userPW;
            
            User temp;
            temp.setId(userID);
            temp.setPw(userPW);
            temp.setName(name);
            
            users = userUtil.addUser(users,userSize,temp);
            
         }
         
    }

}