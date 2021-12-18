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

struct deque{
    queue_node * front;
    queue_node * rear;
    int size;
    
    deque(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    ~deque(){
        queue_node * n = front;
        while(n){
            queue_node * temp = n;
            n = n->next;
            delete(temp);
        }
    }
    
    void enqueue_rear(int x){
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
        cout<<x<<" was added to the rear of queue"<<endl;
    }

    void enqueue_front(int x){
        if(size==0){
            queue_node *n = new queue_node(x);
            front = n;
            rear = n;
            size++;
        }
        else{
            queue_node *n = new queue_node(x);
            n->next = front;
            front = n;
            size++;
        }
        cout<<x<<" was added to the front of deque"<<endl;
    }

    void dequeue_front(){
        if(size==0)
            cout<<"Deque underflow"<<endl;
        else{
            queue_node* temp = front;
            cout<<temp->val<<" was popped from the front of deque"<<endl;
            front = front->next;
            delete(temp);
            size--;
        }
        if(front==NULL)
            rear=NULL;
    }

    void dequeue_rear(){
        if(size==0)
            cout<<"Deque underflow"<<endl;
        else{
            queue_node* temp = front;
            while(temp->next!=rear){
                temp = temp->next;
            }
            cout<<(temp->next)->val<<" was popped from the rear of deque"<<endl;
            rear = temp;
            temp = temp->next;
            delete(temp);
            rear->next = NULL;
            size--;
        }
        if(rear==NULL)
            front=NULL;
    }

    int peek_front(){
        if(size==0)
            cout<<"Deque underflow"<<endl;
        else
            return front->val;
    }

    int peek_back(){
        if(size==0)
            cout<<"Deque underflow"<<endl;
        else
            return rear->val;
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
    deque x;
    x.enqueue_front(10);
    x.print();
    x.enqueue_front(5);
    x.print();
    x.enqueue_front(3);
    x.print();
    x.enqueue_rear(6);
    x.print();
    x.enqueue_rear(7);
    x.print();
    cout<<"Element at front is "<<x.peek_front()<<endl;
    cout<<"Element at rear is "<<x.peek_back()<<endl;
    x.dequeue_front();
    x.print();
    x.dequeue_rear();
    x.print();
    x.dequeue_front();
    x.print();
    x.dequeue_rear();
    x.print();
    x.dequeue_front();
    x.print();
    x.peek_back();
}