#include <iostream>
using namespace std;

//SLL
struct sll_node{
    int val;
    sll_node * next;
};

struct sllist{
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

    int length(){
        // Complexity O(1)
        return size;
    }

    void print(){
        //Complexity O(n)
        sll_node *n = head;
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
        sll_node *newnode = new sll_node();
        newnode->next = head;
        newnode->val = k;
        head = newnode;
        size++;
    }
    sll_node * search_with_val(int val){
        /* returns the pointer to the first node with
        value equal to val
        */
        // Complexity O(n)
        sll_node *n = head;
        while(n!=NULL){
            if(n->val==val){
                return n;
            }
            n = n->next;
        }
    }

    void delete_node(sll_node* p){
        /* deletes the node with pointer p and joins the node
        prev of p to the one next of p.
        */
        // Complexity O(n)
        sll_node *prev = head;
        while(prev->next != p){
            prev = prev->next;
        }
        prev->next = p->next;
        delete p;
        size--;
    }

    void insert_after_node(sll_node *p, int k){
        /* inserts a node after node pointed by p 
        which holds the value k
        */
        // Complexity O(n)
        sll_node* n = new sll_node();
        n->val = k;
        n->next = p->next;
        p->next = n;
        size++;
    }

    sll_node * get_head(){
        // Complexity O(1)
        return head;
    }
};

//DLL
struct dll_node{
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
        top = NULL;
    }

    ~stack(){        
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

//Queue
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
