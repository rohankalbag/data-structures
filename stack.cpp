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

int main(){
    stack x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.print();
    x.peek();
    x.pop();
    x.peek();
    x.pop();
    x.peek();
}