#include <iostream>
using namespace std;

template <typename T> struct node{
//nodes
    T val;
    node<T> * next;
    node<T> * prev;

    node(T x){
        next=nullptr;
        prev=nullptr;
        val = x;
    }
};

template <typename T> struct dllist{
    int len;
    node<T> * head;
    node<T> * tail;

    dllist(){
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    ~dllist(){
        node<T>* n = head;
        while(n){
            node<T>* temp = n;
            n = n->next;
            delete(temp);
        }
    }

    void fprint(){
        /*forward traversal*/
        //Time Complexity O(n)
        cout<<"<=";
        node<T> *n = head;
        while(n){
            cout << "[" << n->val << "]" << "=";
            n = n->next;
        }
        cout<<">"<<endl;
    }

    void rprint(){
        /*reverse traversal*/
        //Time Complexity O(n)
        cout<<"<=";
        node<T> *n = tail;
        while(n){
            cout << "[" << n->val << "]" << "=";
            n = n->prev;
        }
        cout<<">"<<endl;
    }

    int size(){
        return len;
    }

    void insert_at_head(T x){
        if(head){
            node<T>* n = new node<T>(x);
            n->next = head;
            n->prev = nullptr;
            head->prev = n;
            head = n;
            len++;
        }
        else{
            node<T>* n = new node<T>(x);
            n->next = nullptr;
            n->prev = nullptr;
            head = n;
            tail = n;
            len++;
        }
    }

    void insert_at_tail(T x){
        if(tail){
            node<T>* n = new node<T>(x);
            tail->next = n;
            n->prev = tail;
            n->next = nullptr;
            tail = n;
            len++;
        }
        else{
            node<T>* n = new node<T>(x);
            n->next = nullptr;
            n->prev = nullptr;
            head = n;
            tail = n;
            len++;
        }
    }

    T remove_at_head(){
        if(len>0){
            T val = head->val;
            node<T> * n = head;
            (head->next)->prev = nullptr;
            head = head->next;
            if(len==1)
                tail = nullptr;
            delete n;
            len--;
            return val;
        }
        cout<<"No value to be removed!"<<endl;
    }

    T remove_at_tail(){
        if(len>0){
            T val = tail->val;
            node<T> * n = tail;
            (tail->prev)->next = nullptr;
            tail = tail->prev;
            if(len==1)
                head = nullptr;
            delete n;
            len--;
            return val;
        }
        cout<<"No value to be removed!"<<endl;
    }
};

int main(){
    dllist<char> d;
    d.insert_at_head('a');
    d.insert_at_tail('b');
    d.insert_at_head('c');
    d.insert_at_tail('d');
    cout<<d.size()<<endl;
    d.fprint();
    d.rprint();
    cout<<d.remove_at_head()<<endl;
    cout<<d.remove_at_tail()<<endl;
    cout<<d.head->val<<endl;
    cout<<d.tail->val<<endl;
    d.fprint();
    return 0;
}
