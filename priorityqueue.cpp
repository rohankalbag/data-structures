#include <iostream>
#include <vector>
using namespace std;

struct priorityqueue{
    //based on min binary heap
    //the heap invariant is val(parent) <= val(child)
    vector<int>* binaryheap;

    priorityqueue(){
        binaryheap = new vector<int>();
    }

    ~priorityqueue(){
        delete binaryheap;
    }

    int size(){
        return binaryheap->size();
    }

    bool compare(int ind1, int ind2){
        //check if heap conditional is satisfied for two indices
        //ind1 and ind2 are parent and child respectively
        if((*binaryheap)[ind1] <= (*binaryheap)[ind2]){
            return true;
        }
        return false;
    }

    void swap(int ind1, int ind2){
        // swap values of the minheap at indices ind1 and ind2
        int temp = (*binaryheap)[ind1];
        (*binaryheap)[ind1] = (*binaryheap)[ind2];
        (*binaryheap)[ind2] = temp;
    }

    int val(int ind1){
        // return value of minheap at index ind1
        return (*binaryheap)[ind1];
    }

    void bubbleup(int index){
        // keep moving the value up the heap until heap invariant is satisfied
        // O(log(n))
        int parent = (index-1)/2;
        while(index > 0 && !compare(parent, index)){
            swap(parent, index);
            index = parent;
            parent = (index-1)/2;
        }
    }

    void add(int m){
        // add element to priority queue following heap invariant
        // O(log(n))
        binaryheap->push_back(m);
        bubbleup(size()-1);
    }

    void bubbledown(int index){
        //keep moving the element down until heap invariant is satisfied
        //if two children are equally likely then choose the left one
        //O(log(n))
        while(true){
            int right = 2*index + 2;
            int left = 2*index + 1;
            if(left < size()){
                int smallest = left;
                if(right < size()){
                    if(val(right) >= val(left))
                        smallest = left;
                    else
                        smallest = right;
                }

                if(!compare(index, smallest)){
                    swap(index, smallest);
                    index = smallest;
                }
            }
            else
                break;
        }
    }

    int removeAtIndex(int index){
        //remove element at position index from the binary heap
        //O(log(n))
        swap(index, size()-1);
        int value = val(size()-1);
        binaryheap->pop_back();
        int elem = val(index);
        bubbledown(index);
        if(val(index) == elem){
            bubbleup(index);
        }
        return value;
    }

    int poll(){
        //remove element from priority queue with highest priority
        //O(log(n))
        return removeAtIndex(0);
    }

    int peek(){
        //see element with highest priority
        //O(1)
        return (*binaryheap)[0];
    }

    bool removeVal(int value){
        //remove an instance of element with value
        //O(n), can be improved to O(log(n)) using hashing
        int index = -1;
        for(int i=0;i<size();i++){
            //linear search
            if(val(i) == value){
                index = i;
                break;
            }
        }

        if(index==-1){
            return false;
        }

        else{
            int ans = removeAtIndex(index);
            return true;
        }
    }
};

int main(){
    priorityqueue pq;
    pq.add(1);
    pq.add(5);
    pq.add(3);
    pq.add(4);
    pq.add(6);
    pq.add(2);
    cout<<pq.poll()<<endl;
    cout<<pq.poll()<<endl;
    cout<<pq.poll()<<endl;
    cout<<pq.poll()<<endl;
    cout<<pq.poll()<<endl;
    cout<<pq.poll()<<endl;
    pq.add(2);
    pq.add(2);
    pq.add(3);
    pq.removeVal(3) ? cout<<"removed 3" : cout<<"didn't remove 3";
}
