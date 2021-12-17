#include <iostream>
using namespace std;

struct node{
//nodes
    int val;
    node * next;
    node * prev;

    node(int x){
        next=NULL;
        prev=NULL;
        val = x;
    }
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

    void print(){
        //Complexity O(n)
        node *n = head;
        while(n!=NULL){
            cout << "[" << n->val << "]" << "=";
            n = n->next;
        }
        cout<<">"<<endl;
    }

    int length(){
        return size;
    }

    void insert_at_head(int x){
        if(head){
            node* n = new node(x);
            n->next = head;
            head->prev = n;
            head = n;
            size++;
        }
        else{
            node* n = new node(x);
            head = n;
            tail = n;
            size++;
        }
    }

    void insert_at_tail(int x){
        if(tail){
            node* n = new node(x);
            tail->next = n;
            n->prev = tail;
            tail = n;
            size++;
        }
        else{
            node* n = new node(x);
            head = n;
            tail = n;
            size++;
        }
    }
    
    node* get_head(){
        return head;
    }

    node* get_tail(){
        return tail;
    }
};

int main(){
    dllist dll;
    dll.insert_at_head(1);
    dll.print();
    cout<<dll.get_head()->val<<endl;
    cout<<dll.get_tail()->val<<endl;
    dll.insert_at_head(3);
    dll.print();
    cout<<dll.get_head()->val<<endl;
    cout<<dll.get_tail()->val<<endl;
    dll.insert_at_head(4);
    dll.print();
    cout<<dll.get_head()->val<<endl;
    cout<<dll.get_tail()->val<<endl;
    dll.insert_at_tail(2);
    dll.print();
    cout<<dll.get_head()->val<<endl;
    cout<<dll.get_tail()->val<<endl;
    cout<<"Length: "<<dll.length()<<endl;
}