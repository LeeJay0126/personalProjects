#include "Player.h"
#include "Node.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

template<typename T>
void pushData(T** n, string header[]);
template<typename T>
void readFile(T** head_ref, string filename, string header[]);
template<typename T>
void display(T * n);
template<typename T>
void assignTeams(T * n);

template<typename T>
void assignTeams(T * n){
    T p;
    Player bucksPlayers [15];
    Player lakersPlayers [15];
    Player netsPlayers [15];
    Player warriorsPlayers [15];
    int bucksCount = 0;
    int lakersCount = 0;
    int netsCount = 0;
    int warriorsCount = 0;
    
    while(n != nullptr){
       
        p = n->getElement();
        int assignedPlayer = 0;
        while(assignedPlayer == 0){
            int assignment = rand() % 4 + 1;
            if(netsCount == bucksCount && lakersCount == bucksCount && warriorsCount == bucksCount){
                if(assignment == 1){
                    bucksPlayers[bucksCount] = p.getElement();
                    bucksCount ++;
                    assignedPlayer++;
                }
                if(assignment == 2){
                    lakersPlayers[lakersCount] = p.getElement();
                    lakersCount ++;
                    assignedPlayer++;
                }
                if(assignment == 3){
                    netsPlayers[netsCount] = p.getElement();
                    netsCount ++;
                    assignedPlayer++;
                }
                if(assignment == 4){
                    warriorsPlayers[warriorsCount] = p.getElement();
                    warriorsCount ++;
                    assignedPlayer++;
                }
            }
            if(assignment == 1 && bucksCount <= lakersCount && bucksCount <= netsCount && bucksCount <= warriorsCount){
                bucksPlayers[bucksCount] = p.getElement();
                bucksCount++;
                assignedPlayer++;
            
            }
            if(assignment == 2 && lakersCount <= bucksCount && lakersCount <= netsCount && lakersCount <= warriorsCount){
                lakersPlayers[lakersCount] = p.getElement();
                lakersCount++;
                assignedPlayer++;
            
            }
            if(assignment == 3 && netsCount <= bucksCount && netsCount <= lakersCount && netsCount <= warriorsCount){
                netsPlayers[netsCount] = p.getElement();
                netsCount++;
                assignedPlayer++;
            
            }
            if(assignment == 4 && warriorsCount <= lakersCount && warriorsCount <= netsCount && warriorsCount <= bucksCount){
                warriorsPlayers[warriorsCount] = p.getElement();
                warriorsCount++;
                assignedPlayer++;
            
            }
        }
        n = n->next;
    }
    int teamSelection;
    int count = 0;
    cout << "select you team \n1.bucks\n2.lakers\n3.nets\n4.warriors" << endl;
    cin >> teamSelection;
    if (teamSelection == 1){
        while (count <= (sizeof(bucksPlayers)/sizeof(*bucksPlayers)) - 1){
            cout << count << ". " << bucksPlayers[count].getName() << endl;
            count ++;
        }
    }
    if (teamSelection == 2){
        while (count <= (sizeof(lakersPlayers)/sizeof(*lakersPlayers)) - 1){
            cout << count << ". " << lakersPlayers[count].getName() << endl;
            count ++;
        }
    }
    if (teamSelection == 3){
        while (count <= (sizeof(netsPlayers)/sizeof(*netsPlayers)) - 1){
            cout << count << ". " << netsPlayers[count].getName() << endl;
            count ++;
        }
        
    }
    if (teamSelection == 4){
        while (count <= (sizeof(warriorsPlayers)/sizeof(*warriorsPlayers)) - 1){
            cout << count << ". " << warriorsPlayers[count].getName() << endl;
            count ++;
        }
    }
    cout << "these are you players" << endl;
    int value;
    int playerSelection;
    int option;
    while (option != 3){
        cout << "1. add player to trade  \n2. add draft pick\n3. select the other team you would like to trade to" << endl;
        cin >> option;
        if(option == 1){
            cout << "whick player would you like to add to the trade";
            cin >> playerSelection;
            if (teamSelection == 1){
                value = value + bucksPlayers[playerSelection].getPlayerWorth();
            }
            if (teamSelection == 2){
                value = value + lakersPlayers[playerSelection].getPlayerWorth();
            }
            if (teamSelection == 3){
                value = value + netsPlayers[playerSelection].getPlayerWorth();
            }
            if (teamSelection == 4){
                value = value + warriorsPlayers[playerSelection].getPlayerWorth();
            }
        }
        if(option == 2){
            int year = 2021;
            count = 0;
            int draftPick;
            cout << "which pick would you like to trade" << endl;
            while (year <= 2026){
                cout << count << ". " << year << " "  << "first" << endl;
                count ++;
                cout << count << ". " << year << " "  << "second" << endl;
                year ++;
                count ++;
            }
            cin >> draftPick;
            int draftPickValue = 0;
            int yearsAway = (2021 + draftPick/2) - 2021;
            if(draftPick % 2 == 0){
                draftPickValue = 50 - (yearsAway * 2);
            }
            else{
                draftPickValue = 30 - (yearsAway * 2);
            }
            value = value + draftPickValue;
        }
    }
    
    
    cout << "which team would you like to trade with" << endl;
    int otherTeamSelection;
    if (teamSelection == 1){
        cout <<"1.lakers \n2.nets \n3.warriors";
        cin >> otherTeamSelection;
        if (otherTeamSelection == 1){
            teamSelection = 2;
        }
        if (otherTeamSelection == 2){ //1.bucks\n2.lakers\n3.nets\n4.warriors
            teamSelection = 3;
        }
        if (otherTeamSelection == 3){
            teamSelection = 4;
        }
    }
    else if (teamSelection == 2){
        cout <<"1.bucks \n2.nets \n3.warriors";
        if (otherTeamSelection == 1){
            teamSelection = 1;
        }
        if (otherTeamSelection == 2){ 
            teamSelection = 3;
        }
        if (otherTeamSelection == 3){
            teamSelection = 4;
        }
    }
    else if (teamSelection == 3){
        cout <<"1.bucks \n2.lakers \n3.warriors";
        if (otherTeamSelection == 1){
            teamSelection = 1;
        }
        if (otherTeamSelection == 2){ 
            teamSelection = 2;
        }
        if (otherTeamSelection == 3){
            teamSelection = 4;
        }
    }
    else if (teamSelection == 4){
        cout <<"1.bucks \n2.lakers \n3.nets";
        if (otherTeamSelection == 1){
            teamSelection = 1;
        }
        if (otherTeamSelection == 2){ 
            teamSelection = 2;
        }
        if (otherTeamSelection == 3){
            teamSelection = 3;
        }
    }
    
    if (teamSelection == 1){
        while (count <= (sizeof(bucksPlayers)/sizeof(*bucksPlayers)) - 1){
            cout << count << ". " << bucksPlayers[count].getName() << endl;
            count ++;
        }
    }
    if (teamSelection == 2){
        while (count <= (sizeof(lakersPlayers)/sizeof(*lakersPlayers)) - 1){
            cout << count << ". " << lakersPlayers[count].getName() << endl;
            count ++;
        }
    }
    if (teamSelection == 3){
        while (count <= (sizeof(netsPlayers)/sizeof(*netsPlayers)) - 1){
            cout << count << ". " << netsPlayers[count].getName() << endl;
            count ++;
        }
        
    }
    if (teamSelection == 4){
        while (count <= (sizeof(warriorsPlayers)/sizeof(*warriorsPlayers)) - 1){
            cout << count << ". " << warriorsPlayers[count].getName() << endl;
            count ++;
        }
    }
    cout << "these are the availible players on the other team" << endl;
    int otherTeamValue;
    option = -1;
    while (option != 3){
        cout << "1. add player to trade  \n2. add draft pick\n3. see if the trade will work out" << endl;
        cin >> option;
        if(option == 1){
            cout << "whick player would you like to add to the trade";
            cin >> playerSelection;
            if (teamSelection == 1){
                otherTeamValue = otherTeamValue + bucksPlayers[playerSelection].getPlayerWorth();
            }
            if (teamSelection == 2){
                otherTeamValue = otherTeamValue + lakersPlayers[playerSelection].getPlayerWorth();
            }
            if (teamSelection == 3){
                otherTeamValue = otherTeamValue + netsPlayers[playerSelection].getPlayerWorth();
            }
            if (teamSelection == 4){
                otherTeamValue = otherTeamValue + warriorsPlayers[playerSelection].getPlayerWorth();
            }
        }
        if(option == 2){
            int year = 2021;
            count = 0;
            int draftPick;
            cout << "which pick would you like to trade" << endl;
            while (year <= 2026){
                cout << count << ". " << year << " "  << "first" << endl;
                count ++;
                cout << count << ". " << year << " "  << "second" << endl;
                year ++;
                count ++;
            }
            cin >> draftPick;
            int draftPickValue = 0;
            int yearsAway = (2021 + draftPick/2) - 2021;
            if(draftPick % 2 == 0){
                draftPickValue = 50 - (yearsAway * 2);
            }
            else{
                draftPickValue = 30 - (yearsAway * 2);
            }
            otherTeamValue = otherTeamValue + draftPickValue;
        }
        int tradeProbability = abs(value - otherTeamValue);
        if(tradeProbability <= 15){
            cout << "the trade will most likely work" << endl;
        }
        
        if(tradeProbability > 15 && tradeProbability <= 30){
            cout << "you will have a hard time convincing the other GM for this trade" << endl;
        }
        if(tradeProbability > 30){
            cout << "this trade most likely will not work" << endl;
        }
    } 
}



template<typename T>
void display(T * n, string header[]){
    
    T p;
    
    cout <<left << setw(25) << header[0] << setw(5) << header[1] << setw(10) << header[2]<< setw(10) << header[3]<< setw(10) << header[4]<< setw(10) << header[5]<< setw(10) << header[6]<< setw(15) << header[7]<< setw(15) << header[8]<< setw(15) << header[9]<< setw(20) << header[10]<< setw(20) << header[11]<< setw(20) << header[12]<< setw(10) << header[13]<< setw(10) << header[14]<< setw(10) << header[15]<< setw(10) << header[16]<< setw(10) << header[17]<< setw(15) << header[18]<< setw(10) << header[19] << setw(10) << header[20] <<endl;

    cout << endl;
    
    while(n != nullptr){
        
        p = n->getElement();
        
        /*cout << left << fixed <<setprecision(2) << setw(25) << p.getElement().getName() << setw(5) << p.getElement().getFg() << setw(10) << p.getElement().getRebounds() << setw(10) << p.getElement().getAssists() << setw(10) <<  p.getElement().getSteals() << setw(10) << p.getElement().getBlocks() << setw(10) << p.getElement().getPoints() << setw(15) << p.getElement().getAllNba() << setw(15) << p.getElement().getAllNbaSecond() << setw(15) <<
        p.getElement().getAllNbaThird() << setw(20) << p.getElement().getAllNbaDefense() << setw(20) << p.getElement().getAllNbaDefenseSecond() << setw(20) << p.getElement().getAllNbaDefenseThird() << setw(10) << p.getElement().getAllStarMVP() << setw(10) << p.getElement().getROTY() << setw(10) << p.getElement().getDPOY() << setw(10) << p.getElement().getSMOTY() << setw(10) << p.getElement().getTMOTY() << setw(10) <<
        p.getElement().getScoringTitle() << setw(10) << p.getElement().getFMVP() << setw(10) << p.getElement().getMVP() << setw(10)  << endl;*/
        
        cout << p.getElement().getName() << " " <<  p.getElement().getPlayerWorth() << endl;
        n = n->next;
        
    }
    
    
}


template<typename T>
void readFile(T** head_ref,string filename, string header[]){
    
    ifstream input;
    input.open(filename);
    string line;
    int pos;
    
    Player player;
    int count = 0;
    double sum = 0;
    
    while(getline(input,line)){
        if(count == 0){
            
            pos = line.find(",");
            header[0] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            cout << header[0] << endl;
                        
            pos = line.find(",");
            header[1] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[2] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[3] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[4] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[5] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[6] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[7] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[8] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[9] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[10] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[11] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[12] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[13] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[14] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[15] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[16] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[17] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[18] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[19] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[20] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            header[21] = line;
            
            
            count++;
            
        }else{

            sum = 0;

            pos = line.find(",");
            player.setName(line.substr(0,pos));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setFg(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setRebounds(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAssists(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setSteals(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setBlocks(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setPoints(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllNba(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllNbaSecond(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            
                        
            pos = line.find(",");
            player.setAllNbaThird(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllDefense(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllDefenseSecond(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllDefenseThird(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllStarMVP(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setROTY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setDPOY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setSMOTY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setTMOTY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setScoringTitle(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setFMVP(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setMVP(stoi(line));
            line.erase(0,pos+1);
            
            player.setYearsPro(stoi(line));
            
            sum += player.getPoints() * 2 * player.getFg();
            sum += player.getRebounds() * 4;
            sum += player.getAssists() * 4;
            sum += player.getSteals() * 5;
            sum += player.getBlocks() * 5;
        
            sum += player.getAllNba() * 50;
            sum += player.getAllNbaSecond() * 30;
            sum += player.getAllNbaThird() * 15;
        
            sum += player.getAllNbaDefense() * 50;
            sum += player.getAllNbaDefenseSecond() * 30;
            sum += player.getAllNbaDefenseThird() * 15;
        
            sum += player.getAllStarMVP() * 20;
            sum += player.getROTY() * 30;
            sum += player.getDPOY() * 50;
        
            sum += player.getSMOTY() * 30;
            sum += player.getTMOTY() * 20;
            sum += player.getScoringTitle() * 40;
            sum += player.getFMVP() * 150;
            sum += player.getMVP() * 100;
            
            if (player.getYearsPro() < 5 && sum >= 50){
               sum = sum * 2; 
            }
            
            if(player.getYearsPro() < 15){
                sum = sum + (player.getYearsPro() * 15);
            }
            else{
                sum = sum + (player.getYearsPro() * 12);
            }
    
            player.setPlayerWorth(sum);
            
            pushData(head_ref,player);

        }

        
    }
    
    input.close();

}

template<typename T>
void pushData(T** head_ref, Player data){
    
    T * new_node = new T(data);
    
    new_node->next = (* head_ref);
    
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    
}