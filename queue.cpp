#include <iostream>
using namespace std;

template <typename T> struct node{
//nodes
    T val;
    node<T> * next;
};

template <typename T> struct sllist{
// singly linked list of nodes

    node<T> * head;
    node<T> * tail;
    int len;

    sllist(){
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    ~sllist(){
        node<T> *n = head;
        while(n){
            node<T> * temp = n;
            n = n->next;
            delete temp;
        }
    }

    int size(){
        return len;
    }

    void print(){
        node<T> *n = head;
        while(n){
            cout << "[" << n->val << "]" << "-";
            n = n->next;
        }
        cout<<">"<<endl;
    }

    void insert_at_head(T k){
        /* creates a new node pointing to head with
        value as k
        */
        if(len==0){
            node<T> *newnode = new node<T>();
            newnode->next = head;
            newnode->val = k;
            head = newnode;
            tail = newnode;
            len++;
        }
        else{
            node<T> *newnode = new node<T>();
            newnode->next = head;
            newnode->val = k;
            head = newnode;
            len++;
        }
    }

    void insert_at_tail(T k){
        if(len==0){
            node<T> *newnode = new node<T>();
            newnode->next = tail;
            newnode->val = k;
            head = newnode;
            tail = newnode;
            len++;
        }
        else{
            node<T> *newnode = new node<T>();
            tail->next = newnode;
            newnode->val = k;
            tail = newnode;
            len++;
        }
    }

    T remove_at_head(){
        /*removes element at the head*/
        node<T> * n = head;
        T val = head->val;
        head = head->next;
        if(len==1)
            tail = nullptr;
        delete n;
        len--;
        return val;
    }

    node<T> * search_with_val(T val){
        /* returns the pointer to the first node with
        value equal to val
        */
        node<T> *n = head;
        while(n){
            if(n->val==val){
                return n;
            }
            n = n->next;
        }
        return nullptr;
    }
};

template <typename T> struct queue{
    //queue implemented using a singly linked list
    node<T> * front;
    node<T> * back;
    sllist<T> * list;

    queue(){
        front = nullptr;
        back = nullptr;
        list = new sllist<T>();
    }

    ~queue(){
        delete list;
    }

    int size(){
        return list->size();
    }

    void enqueue(T k){
        list->insert_at_tail(k);
        front = list->head;
        back = list->tail;
    }

    T dequeue(){
        if(size() > 0){
            T val = list->remove_at_head();
            front = list->head;
            back = list->tail;
            return val;
        }
        cout<<"No element to dequeue!"<<endl;
    }

};

int main(){
    queue<int> q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(10);
    cout<<q.size()<<endl;
    cout<<q.front->val<<endl;
    cout<<q.back->val<<endl;
}
