#include <iostream>
using namespace std;

//SLL

struct sll_node{
//nodes
    int val;
    sll_node * next;
};

struct sllist{
// singly linked list of nodes
private:
    sll_node * head;
    int size;

public:
    sllist(){
        head = NULL;
        size=0;
    }

    ~sllist(){
        sll_node *n = head;
        while(n!=NULL){
            sll_node * temp = n; 
            n = n->next;
            delete(temp);
        }
    }
};

//DLL

struct dll_node{
//nodes
    int val;
    dll_node * next;
    dll_node * prev;

    dll_node(int x){
        next=NULL;
        prev=NULL;
        val = x;
    }
};

struct dllist{
private:
    int size;
    dll_node * head;
    dll_node * tail;
public:
    dllist(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~dllist(){
        dll_node* n = head;
        while(n){
            dll_node* temp = n;
            n = n->next;
            delete(temp);
        }
    }

    void print(){
        //Complexity O(n)
        dll_node *n = head;
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
            dll_node* n = new dll_node(x);
            n->next = head;
            head->prev = n;
            head = n;
            size++;
        }
        else{
            dll_node* n = new dll_node(x);
            head = n;
            tail = n;
            size++;
        }
    }

    void insert_at_tail(int x){
        if(tail){
            dll_node* n = new dll_node(x);
            tail->next = n;
            n->prev = tail;
            tail = n;
            size++;
        }
        else{
            dll_node* n = new dll_node(x);
            head = n;
            tail = n;
            size++;
        }
    }
    
    dll_node* get_head(){
        return head;
    }

    dll_node* get_tail(){
        return tail;
    }
};

//Stack
struct stack_node{
    //same as node in SLL
    int val;
    stack_node * next;

    stack_node(int x){
        val = x;
        next = NULL;
    }
};

struct stack{
    stack_node * top;
    
    stack(){
        //constructor
        top = NULL;
    }

    ~stack(){
        //destructor
        while(top){
            pop(false);
        }
    }

    void push(int x){
        stack_node * temp = new stack_node(x);
        temp->next = top;
        top = temp;
        cout<<x<<" was pushed"<<endl;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    void pop(bool userdef = true){
        if(isEmpty()){
            cout<<"Stack Underflow !"<<endl;
        }
        else{
            int popped_val = top->val;
            stack_node* temp = top;
            top = top->next;
            delete(temp);
            if(userdef)
                cout<<popped_val<<" was popped"<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack Underflow !"<<endl;
            return;
        }
        else{
            cout<<"The topmost value is "<<top->val<<endl;
        }
    }

    void print(){
        stack_node* temp = top;
        cout<<"top ->"<<" ";
        while(temp){
            cout<<temp->val<<"|";
            temp = temp->next;
        }
        cout<<"]"<<endl;
    }
};