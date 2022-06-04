#include <iostream>
using namespace std;

template <typename T> struct node{
//nodes
    T val;
    node<T> * next;
};

template <typename T> struct sllist{
// singly linked list of nodes
private:
    node<T> * head;
    node<T> * tail;
    int len;

public:
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
        if(len==1){
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

int main(){
    sllist<int> s;
    s.insert_at_head(4);
    s.insert_at_head(5);
    s.insert_at_head(7);
    s.insert_at_head(8);
    s.print();
    cout<<s.remove_at_head()<<endl;
    cout<<s.search_with_val(7)->next->val<<endl;
    s.print();
    return 0;
}
