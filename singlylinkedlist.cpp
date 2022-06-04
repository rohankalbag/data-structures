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
    int len;

public:
    sllist(){
        head = nullptr;
        len = 0;
    }

    ~sllist(){
        node<T> *n = head;
        while(n){
            node<T> * temp = n;
            n = n->next;
            delete(temp);
        }
    }

    int size(){
        // Time Complexity O(1)
        return len;
    }

    void print(){
        //Time Complexity O(n)
        node<T> *n = head;
        while(n){
            cout << "[" << n->val << "]" << "-";
            n = n->next;
        }
        cout<<">"<<endl;
    }
    void insert_value(T k){
        /* creates a new node pointing to head with
        value as k
        */
        // Time Complexity O(1)
        node<T> *newnode = new node<T>();
        newnode->next = head;
        newnode->val = k;
        head = newnode;
        len++;
    }
    node<T> * search_with_val(T val){
        /* returns the pointer to the first node with
        value equal to val
        */
        // Time Complexity O(n)
        node<T> *n = head;
        while(n){
            if(n->val==val){
                return n;
            }
            n = n->next;
        }
        return nullptr;
    }

    void delete_node(node<T>* p){
        /* deletes the node with pointer p and joins the node
        prev of p to the one next of p.
        */
        // Time Complexity O(n)
        if(p == head){
            head = p->next;
            delete p;
            len--;
            return;
        }
        node<T> *prev = head;
        while(prev->next != p){
            prev = prev->next;
        }
        prev->next = p->next;
        delete p;
        len--;
    }

    void insert_after_node(node<T> *p, T k){
        /* inserts a node after node pointed by p
        which holds the value k
        */
        // Time Complexity O(1)
        node<T>* n = new node<T>();
        n->val = k;
        n->next = p->next;
        p->next = n;
        len++;
    }

    node<T> * get_head(){
        // Time Complexity O(1)
        return head;
    }
};

int main(){
    sllist<int> s;
    s.insert_value(4);
    s.insert_value(5);
    s.insert_value(6);
    s.insert_after_node((s.get_head())->next,7);
    s.delete_node(s.get_head());
    cout<<s.search_with_val(7)->next->val<<endl;
    s.print();
    return 0;
}
