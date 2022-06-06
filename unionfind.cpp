#include<vector>
#include<map>
#include<iostream>

using namespace std;

template <typename T> struct unionfind{
    int initsize;
    vector<int> rind;
    vector<int> sizes;
    map<T,int> hashtable;
    vector<T> objs;

    unionfind(int n, vector<T> objects){
        /*  objects : vector must contain distinct objects
            n : must be > 0
            O(n)
        */
        initsize = n;
        for(int i=0;i<n;i++){
            rind.push_back(i);
            (hashtable)[objects[i]] = i;
            sizes.push_back(1);
            objs.push_back(objects[i]);
        }
    }

    T find(T obj2){
        /*  takes in an object that was passed in objects during creation returns the root object
            also implements path compression technique
            alpha(n)
        */
        int ind = (hashtable)[obj2];
        int root = ind;
        while(root != (rind)[root]){
            root = (rind)[root];
        }
        while(ind != root){
            int parent = (rind)[ind];
            (rind)[ind] = root;
            ind = parent;
        }
        return (objs)[root];
    }

    bool connected(T obj1, T obj2){
        // check if two objects are connected
        // alpha(n)
        return(find(obj1) == find(obj2));
    }

    int compSize(T obj1){
        // return number of components in the group containing obj1
        // alpha(n)
        return (sizes)[(hashtable)[find(obj1)]];
    }

    int noofcomponents(){
        // total number of groups
        // O(1)
        return initsize;
    }

    void unify(T obj1, T obj2){
        //  unify two objects if they are not connected
        //  alpha(n)
        if(connected(obj1,obj2))
            return;
        int ind1 = (hashtable)[find(obj1)];
        int ind2 = (hashtable)[find(obj2)];
        if((sizes)[ind1] < (sizes)[ind2]){
            (sizes)[ind2] += (sizes)[ind1];
            (rind)[ind1] = ind2;
            (sizes)[ind1] = 0;
        }
        else{
            (sizes)[ind1] += (sizes)[ind2];
            (rind)[ind2] = ind1;
            (sizes)[ind2] = 0;
        }

        initsize-=1;
    }
};

int main(){
    vector<char> chars = {'a','b','c','d'};
    unionfind<char> uf(4,chars);
    cout << uf.compSize('a') << endl;
    uf.unify('a','b');
    cout << uf.compSize('a') << endl;
    uf.unify('b','c');
    cout << uf.compSize('a') << endl;
    cout << uf.find('c') << endl;
    uf.unify('a','d');
    cout << uf.noofcomponents() << endl;
    cout << uf.compSize('a') << endl;
    uf.connected('a','d') ? cout << "Connected" : cout << "Disconnected";
}
