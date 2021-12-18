#include <iostream>
using namespace std;

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
        stack_node*n = top;
        while(n){
            stack_node*temp = n;
            n = n->next;
            delete(temp);
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
    
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow !"<<endl;
        }
        else{
            int popped_val = top->val;
            stack_node* temp = top;
            top = top->next;
            delete(temp);
            cout<<popped_val<<" was popped"<<endl;
        }
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack Underflow !"<<endl;
        }
        else{
            return top->val;
        }
    }

    void print(){
        stack_node* temp = top;
        cout<<"top ->"<<" ";
        while(temp){
            if(temp->next!=NULL)
                cout<<temp->val<<"|";
            else
                cout<<temp->val;
            temp = temp->next;
        }
        cout<<"]"<<endl;
    }
};

int main(){
    stack x;
    x.push(1);
    x.print();
    x.push(2);
    x.print();
    x.push(3);
    x.print();
    cout<<x.peek()<<" is the topmost element on peeking"<<endl;
    x.pop();
    x.print();
    cout<<x.peek()<<" is the topmost element on peeking"<<endl;
    x.pop();
    x.print();
    cout<<x.peek()<<" is the topmost element on peeking"<<endl;
}