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
    bool stop = false;
    while(!stop){
        cout<<"Enter 1 to push value into stack"<<endl;
        cout<<"Enter 2 to display stack"<<endl;
        cout<<"Enter 3 to peek the topmost value"<<endl;
        cout<<"Enter 4 to pop the topmost value"<<endl;
        cout<<"Enter 0 to end program"<<endl;
        int n;
        cin>>n;
        if(n==1){
            cout<<"Enter value to insert: "<<endl;
            int c;
            cin>>c;
            x.push(c);
        }
        else if(n==2){
            x.print();
        }
        else if(n==3){
            cout<<x.peek()<<" was the topmost value"<<endl;
        }
        else if(n==4){
            x.pop();
        }
        else if(n==0){
            stop = true;
        }
        else{
            cout<<"Invalid Entry !"<<endl;
        }
    }
}