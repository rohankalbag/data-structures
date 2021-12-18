#include <iostream>
using namespace std;

struct node{
//nodes
    int val;
    node * next;
    node * prev;

    node(int x){
        next=NULL;
        prev=NULL;
        val = x;
    }
};

struct dllist{
private:
    int size;
    node * head;
    node * tail;
public:
    dllist(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~dllist(){
        node* n = head;
        while(n){
            node* temp = n;
            n = n->next;
            delete(temp);
        }
    }

    void print(){
        //Complexity O(n)
        node *n = head;
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
            node* n = new node(x);
            n->next = head;
            head->prev = n;
            head = n;
            size++;
        }
        else{
            node* n = new node(x);
            head = n;
            tail = n;
            size++;
        }
    }

    void insert_at_tail(int x){
        if(tail){
            node* n = new node(x);
            tail->next = n;
            n->prev = tail;
            tail = n;
            size++;
        }
        else{
            node* n = new node(x);
            head = n;
            tail = n;
            size++;
        }
    }
    
    node* get_head(){
        return head;
    }

    node* get_tail(){
        return tail;
    }
};

int main(){
    dllist dll;
    bool stop = false;
    while(!stop){
        cout<<"Enter 1 to insert value into head of DLL"<<endl;
        cout<<"Enter 2 to display DLL"<<endl;
        cout<<"Enter 3 to display length of DLL"<<endl;
        cout<<"Enter 4 to insert value into tail of DLL"<<endl;
        cout<<"Enter 0 to end program"<<endl;
        int n;
        cin>>n;
        if(n==1){
            cout<<"Enter value to insert: "<<endl;
            int c;
            cin>>c;
            dll.insert_at_head(c);
        }
        else if(n==2){
            dll.print();
        }
        else if(n==3){
            cout<<"Length: "<<dll.length()<<endl;
        }
        else if(n==0){
            stop = true;
        }
        else if(n==4){
            cout<<"Enter value to insert: "<<endl;
            int c;
            cin>>c;
            dll.insert_at_tail(c);
        }
        else{
            cout<<"Invalid Entry !"<<endl;
        }
    }
}