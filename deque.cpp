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
            cout<<temp->val<<" was removed from the front of deque"<<endl;
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
            cout<<(temp->next)->val<<" was removed from the rear of deque"<<endl;
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
    bool stop = false;
    while(!stop){
        cout<<"Enter 1 to enqueue value into rear of deque"<<endl;
        cout<<"Enter 2 to enqueue value into rear of deque"<<endl;
        cout<<"Enter 3 to display deque"<<endl;
        cout<<"Enter 4 to peek the front most value"<<endl;
        cout<<"Enter 5 to peek the rear most value"<<endl;
        cout<<"Enter 6 to pop the front most value"<<endl;
        cout<<"Enter 7 to pop the rear most value"<<endl;
        cout<<"Enter 0 to end program"<<endl;
        int n;
        cin>>n;
        if(n==1){
            cout<<"Enter value to insert: "<<endl;
            int c;
            cin>>c;
            x.enqueue_front(c);
        }
        else if(n==2){
            cout<<"Enter value to insert: "<<endl;
            int c;
            cin>>c;
            x.enqueue_rear(c);
        }
        else if(n==3){
            x.print();
        }
        else if(n==4){
            cout<<x.peek_front()<<" was the frontmost value"<<endl;
        }
        else if(n==5){
            cout<<x.peek_back()<<" was the rearmost value"<<endl;
        }
        else if(n==6){
            x.dequeue_front();
        }
        else if(n==7){
            x.dequeue_rear();
        }
        else if(n==0){
            stop = true;
        }
        else{
            cout<<"Invalid Entry !"<<endl;
        }
    }
}