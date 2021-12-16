#include <iostream>
using namespace std;

struct node{
//nodes
    int val;
    node * next;
    node * prev;
};

struct dllist{
private:
    int size;
    node * head;
    node * tail;
public:
    dllist(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~dllist(){
        node* n = head;
        while(n){
            node* temp = n;
            n = n->next;
            delete(temp);
        }
    }

    int length(){
        
    }

};