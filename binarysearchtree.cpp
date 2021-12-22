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
    
    bs_tree(){
        root = NULL;
    }

    void insert(bt_node* &node, int val){
        if(node==NULL){
            node = new bt_node(val);
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
    
    int k;
    cout<<"Enter value to find"<<endl;
    cin>>k;
    tree.find(k) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;

}