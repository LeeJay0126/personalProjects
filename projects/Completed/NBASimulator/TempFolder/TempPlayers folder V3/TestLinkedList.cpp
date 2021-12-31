#include "Player.h"
#include "Node.h"
#include "PlayerUtil.cpp"
#include <iostream>
#include <iomanip>
#include <string>

int main(){
    
    Node<Player> *head = nullptr;
    string header[22];
    
    cout << "head's address : " << &head << endl;
    
    readFile(&head, "NbaPlayers.csv",header);
    display(head, header);
    
    return 0;
    
    
}