#include <iostream>
#include <queue>
using namespace std;

template <typename T> struct node{
    //nodes for binary search tree
    node<T> * right;
    node<T> * left;
    T val;

    node(T v){
        val = v;
        right = nullptr;
        left = nullptr;
    }
};

template <typename T> struct BinarySearchTree{
    //must contain comparable data (<, >, ==) operations must exist
    int number;
    node<T> * root;

    BinarySearchTree(){
        number=0;
        root = nullptr;
    }

    int size(){
        //O(1)
        return number;
    }

    bool isempty(){
        //O(1)
        return (size()==0);
    }

    int compare(node<T>* n, T v){
        //O(1)
        if(v > n->val){
            return 1;
        }
        else if(v < n->val){
            return -1;
        }
        else{
            return 0;
        }
    }

    bool search(node<T>* n, T v){
        //return true if node is found with value v, else return false
        // Average case O(log n), Worst case O(n)
       if(n == nullptr){
            return false;
       }
       else{
            int comp = compare(n, v);
            if(comp > 0){
                return search(n->right, v);
            }
            else if(comp < 0){
                return search(n->left, v);
            }
            else{
                return true;
            }
       }
    }


    void insert(T v){
        //we won't allow duplicate values
        //insert a node into the tree with value v
        // Average case O(log n), Worst case O(n)
        if(root==nullptr){
            add(root, v);
        }
        else{
            if(!search(root, v)){
                add(root, v);
            }
        }
    }

    void add(node<T>* &n, T v){
        //insertion recursion
        // Average case O(log n), Worst case O(n)
        if(n==nullptr){
            n = new node<T>(v);
            number++;
            return;
        }
        else{
            int comp = compare(n, v);
            if(comp > 0){
                add(n->right, v);
            }
            else{
                add(n->left, v);
            }
        }
    }

    node<T>* getLeftMost(node<T>* n){
        //get node with smallest value in a subtree with root as n
        // Average case O(log n), Worst case O(n)
        while(n->left != nullptr){
            n = n->left;
        }
        return n;
    }

    node<T>* remove(node<T>* &n, T v){
        //removal recursion
        // Average case O(log n), Worst case O(n)
        if(n == nullptr){
            return nullptr;
       }
       else{
            int comp = compare(n, v);
            if(comp > 0){
                n->right = remove(n->right, v);
            }
            else if(comp < 0){
                n->left = remove(n->left, v);
            }
            else{
                if(n->left == nullptr){
                    node<T>* m = n->right;
                    delete(n);
                    return m;
                }
                else if(n->right == nullptr){
                    node<T>* m = n->left;
                    delete(n);
                    return m;
                }
                else{
                    node<T>* m = getLeftMost(n->right);
                    n->val = m->val;
                    n->right = remove(n->right, m->val);
                }
            }
       }
    }

    void remove(T v){
        //remove a node with value n
        // Average case O(log n), Worst case O(n)
        if(search(root, v)){
            remove(root, v);
            number--;
        }
    }

    void preorder(node<T>* n){
        //O(n)
        if(n==nullptr){
            return;
        }
        else{
            cout<<n->val<<" ";
            preorder(n->left);
            preorder(n->right);
        }
    }

    void postorder(node<T>* n){
        //O(n)
        if(n==nullptr){
            return;
        }
        else{
            postorder(n->left);
            postorder(n->right);
            cout<<n->val<<" ";
        }
    }

    void inorder(node<T>* n){
        //O(n)
        if(n==nullptr){
            return;
        }
        else{
            inorder(n->left);
            cout<<n->val<<" ";
            inorder(n->right);
        }
    }

    void levelorder(int p=0){
        //O(n)
        //Breadth First Search
        queue<node<T>*> nodes;
        if(p==1){
            //will be used to free memory at the end
            nodes.push(root);
            while(nodes.size()>0){
                node<T>* n = nodes.front();
                if(n->left)
                    nodes.push(n->left);
                if(n->right)
                    nodes.push(n->right);
                nodes.pop();
                delete(n);
            }
        }
        else{
            nodes.push(root);
            while(nodes.size()>0){
                node<T>* n = nodes.front();
                cout<<n->val<<" ";
                if(n->left)
                    nodes.push(n->left);
                if(n->right)
                    nodes.push(n->right);
                nodes.pop();
            }
            cout<<endl;
        }
    }

    ~BinarySearchTree(){
        levelorder(1);
    }

};

int main(){
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(15);
    bst.insert(17);
    bst.insert(4);

    bst.levelorder();
    bst.inorder(bst.root);
    cout<<endl;
    bst.preorder(bst.root);
    cout<<endl;
    bst.postorder(bst.root);
    cout<<endl;

    bst.remove(5);
    bst.remove(3);
    bst.levelorder();
    cout<<bst.size()<<endl;
    if(bst.search(bst.root, 4)) cout<<"YES";
    if(bst.search(bst.root, 3)) cout<<"YES";
}
