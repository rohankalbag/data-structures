#include <bits/stdc++.h>
using namespace std;

struct trienode{
    //has support for lowercase strings
    trienode * children[26];
    bool isLeaf;

    trienode(){
        isLeaf = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }

    ~trienode(){
        for(int i=0;i<26;i++){
            delete(children[i]);
        }
    }
};

struct trie{
    //trie data structure
    trienode* root;

    trie(){
        root = new trienode;
    }

    string to_lowercase(string s){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        return s;
    }

    void insert(string s){
        //inserts the lowercase word in the trie
        s = to_lowercase(s);
        trienode * n = root;
        for(int i=0; i<(int)s.size();i++){
            int index = s[i] - 'a';
            if(n->children[index]){
                n = n->children[index];
            }
            else{
                n->children[index] = new trienode;
                n = n->children[index];
            }
        }
        n->isLeaf = true;
    }

    bool search(string s){
        //checks if lowercase exists in the tree
        s = to_lowercase(s);
        trienode * n = root;
        for(int i=0;i<(int)s.size();i++){
            int index = s[i] - 'a';
            if(n->children[index]){
                n = n->children[index];
            }
            else{
                return false;
            }
        }
        return (n->isLeaf);
    }

    void alphabetical(){
        preorder(root);
        cout<<endl;
    }

    void preorder(trienode * n, string s = ""){
        if(n == nullptr)
            return;
        else{
            for(int i=0;i<26;i++){
                if(n->children[i]!=nullptr){
                    if(n->children[i]->isLeaf){
                        s.push_back(char(i+97));
                        cout<<s<<endl;
                    }
                    else{
                        string t = s;
                        t.push_back(char(i+97));
                        preorder(n->children[i], t);
                    }
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> testcases = {"hello","help","demon","cat","cast","cartwheel"};
    trie p;

    for(auto x: testcases){
        p.insert(x);
    }

    p.alphabetical();

    string k = "hello";
    p.search(k) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    k = "denim";
    p.search(k) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    k = "demon";
    p.search(k) ? cout<<"YES" : cout<<"NO";
}
