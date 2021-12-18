#include <iostream>
using namespace std;

struct queue_node{
    int val;
    queue_node * next;

    queue_node(int x){
        val = x;
        next = NULL;
    }
};

struct queue{
    queue_node * front;
    queue_node * rear;
    int size;
    
    queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    ~queue(){
        queue_node * n = front;
        while(n){
            queue_node * temp = n;
            n = n->next;
            delete(temp);
        }
    }
    
    void enqueue(int x){
        if(size==0){
            queue_node *n = new queue_node(x);
            front = n;
            rear = n;
            size++;
        }
        else{
            queue_node *n = new queue_node(x);
            rear->next = n;
            rear = n;
            size++;
        }
        cout<<x<<" was added to the queue"<<endl;
    }

    void dequeue(){
        if(size==0)
            cout<<"Queue underflow"<<endl;
        else{
            queue_node* temp = front;
            cout<<temp->val<<" was popped from the queue"<<endl;
            front = front->next;
            delete(temp);
            size--;
        }
        if(front==NULL)
            rear=NULL;
    }

    int peek(){
        if(size==0)
            cout<<"Queue underflow"<<endl;
        else
            return front->val;
    }

    bool isEmpty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void print(){
        if(size==0)
            cout<<"-><-"<<endl;
        else{
            cout<<"f -> ";
            queue_node * n = front;
            while(n){
                if(n==rear)
                    cout<<n->val;
                else
                    cout<<n->val<<" | ";
                n = n->next;
            }
            cout<<" <- r"<<endl;
        }
    }

};


int main(){
    queue x;
    x.print();
    x.enqueue(10);
    x.print();
    x.enqueue(5);
    x.print();
    x.enqueue(7);
    x.print();
    cout<<"Element at front is "<<x.peek()<<endl;
    x.dequeue();
    x.print();
    x.dequeue();
    x.print();
}