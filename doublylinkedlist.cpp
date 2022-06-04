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
private:
    int len;
    node<T> * head;
    node<T> * tail;
public:
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

    node<T>* get_head(){
        return head;
    }

    node<T>* get_tail(){
        return tail;
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
    return 0;
}
