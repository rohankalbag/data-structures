#include <iostream>
using namespace std;

struct bt_node{
    int val;
    bt_node* right;
    bt_node* left;
    
    bt_node(int x){
        right=NULL;
        left= NULL;
        val = x;
    }
};

struct bs_tree{
    bt_node* root;
    int size;

    bs_tree(){
        root = NULL;
    }

    void insert(bt_node* &node, int val){
        if(node==NULL){
            node = new bt_node(val);
            size++;
        }
        else{
            if(val==node->val){
                return;
            }
            else if(val>node->val){
                insert(node->right,val);
            }
            else{
                insert(node->left,val);
            }
        }
    }

    bool find(bt_node* &node, int val){
        if(node==NULL){
            return false;
        }
        if(val==node->val){
                return true;
        }
        else{
            if(val>node->val){
                return find(node->right,val);
            }
            else{
                return find(node->left, val);
            }
        }
    }

    void insert(int val){
        insert(root,val);
    }

    bool find(int k){
        return find(root,k);
    }

    void inorder(bt_node* &node){
        if(node==NULL){
            return;
        }
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }

    void preorder(bt_node* &node){
        if(node==NULL){
            return;
        }
        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right); 
    }

    void postorder(bt_node* &node){
        if(node==NULL){
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout<<node->val<<" ";
    }

    void inorder(){
        inorder(root);
        cout<<endl;
    }

    void preorder(){
        preorder(root);
        cout<<endl;
    }

    void postorder(){
        postorder(root);
        cout<<endl;
    }
};


int main(){

    int n;
    cout<<"Enter no of values in the binary search tree"<<endl;
    cin>>n;
    bs_tree tree;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        tree.insert(x);
    }
    bool stop = false;

    while(!stop){
        cout<<"Enter 1 to traverse the tree inorder"<<endl;
        cout<<"Enter 2 to traverse the tree preorder"<<endl;
        cout<<"Enter 3 to traverse the tree postorder"<<endl;
        cout<<"Enter 0 to continue to next part"<<endl;
        int x;
        cin>>x;
        switch(x){
            case 0:
                stop = true;
                break;
            case 1:
                tree.inorder();
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.postorder();
                break;
            default:
                cout<<"Invalid entry"<<endl;
                break;
        }
    }
    int k;
    cout<<"Enter value to find"<<endl;
    cin>>k;
    tree.find(k) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
}