#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

template<typename T>
class Node{
    public:
        Node *next;
        
        Node(){
            next = nullptr;
        }
        
        Node(T p){
            this->p = p;
            next = nullptr;
        }
        
        
        
        T getElement() const{
            return p;
        }
        
        private:
            T p;
};
#endif