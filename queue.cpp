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
            cout<<temp->val<<" was removed from the queue"<<endl;
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
    bool stop = false;
    while(!stop){
        cout<<"Enter 1 to enqueue value into rear of queue"<<endl;
        cout<<"Enter 2 to display queue"<<endl;
        cout<<"Enter 3 to peek the front most value"<<endl;
        cout<<"Enter 4 to pop the front most value"<<endl;
        cout<<"Enter 0 to end program"<<endl;
        int n;
        cin>>n;
        if(n==1){
            cout<<"Enter value to insert: "<<endl;
            int c;
            cin>>c;
            x.enqueue(c);
        }
        else if(n==2){
            x.print();
        }
        else if(n==3){
            cout<<x.peek()<<" was the frontmost value"<<endl;
        }
        else if(n==4){
            x.dequeue();
        }
        else if(n==0){
            stop = true;
        }
        else{
            cout<<"Invalid Entry !"<<endl;
        }
    }
}