#include <iostream>
using namespace std;

struct node{
//nodes
    int val;
    node * next;
};

struct sllist{
// singly linked list of nodes
private:
    node * head;
    int size;

public:
    sllist(){
        head = NULL;
        size=0;
    }

    ~sllist(){
        node *n = head;
        while(n!=NULL){
            delete n;
            n = n->next;
        }
    }

    int length(){
        // Complexity O(1)
        return size;
    }

    void print(){
        //Complexity O(n)
        node *n = head;
        while(n!=NULL){
            cout << "[" << n->val << "]" << "-";
            n = n->next;
        }
        cout<<">"<<endl;
    }
    void insert_value(int k){
        /* creates a new node pointing to head with
        value as k
        */
        // Complexity O(1)
        node *newnode = new node();
        newnode->next = head;
        newnode->val = k;
        head = newnode;
        size++;
    }
    node * search_with_val(int val){
        /* returns the pointer to the first node with
        value equal to val
        */
        // Complexity O(n)
        node *n = head;
        while(n!=NULL){
            if(n->val==val){
                return n;
            }
            n = n->next;
        }
    }

    void delete_node(node* p){
        /* deletes the node with pointer p and joins the node
        prev of p to the one next of p.
        */
        // Complexity O(n)
        node *prev = head;
        while(prev->next != p){
            prev = prev->next;
        }
        prev->next = p->next;
        delete p;
        size--;
    }

    void insert_after_node(node *p, int k){
        /* inserts a node after node pointed by p 
        which holds the value k
        */
        // Complexity O(n)
        node* n = new node();
        n->val = k;
        n->next = p->next;
        p->next = n;
        size++;
    }
};

int main(){
    return 0;
}