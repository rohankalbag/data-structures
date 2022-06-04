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

template <typename T> struct stack{
//stack based on singly linked list
private:
    node<T>* top;
    sllist<T>* list;
public:
    stack(){
        sllist<T> s;
        list = new sllist<T>();
        top = nullptr;
    }

    ~stack(){
        delete list;
    }

    int size(){
        return list->size();
    }

    void push(T val){
        list->insert_at_head(val);
        top = list->head;
    }

    bool isempty(){
        return (list->size()==0);
    }

    T pop(){
        if(isempty())
            cout<<"No element in stack!"<<endl;
        else{
            T val = list->remove_at_head();
            top = list->head;
            return val;
        }
    }

    T peek(){
        if(isempty())
            cout<<"No element in stack!"<<endl;
        else
            return top->val;
    }

};

int main(){
    stack<char> s;
    s.push('a');
    s.push('b');
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    s.push('w');
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
}
