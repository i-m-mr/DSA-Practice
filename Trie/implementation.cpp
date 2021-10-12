#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    Node* arr[26];
    bool flag = false;

    bool contains(char c) {
        return (arr[c-'a'] != NULL);
    }
    void put(char c, Node* newNode) {
        arr[c-'a'] = newNode;
    }
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    void setFlag() {
        flag = true;
    }
    bool isFlagSet() {
        return flag;
    }
};

Node* root = new Node();

void insert(string word) {
    Node* temp = root;
    for(int i=0; i<word.size(); i++) {
        // check if letter is already contained in trie
        if(!temp->contains(word[i])) {
            Node* newNode = new Node();
            temp->put(word[i], newNode);
        }
        temp = temp->getNext(word[i]);
    }
    temp->setFlag();
}

bool search(string word) {
    Node* temp = root;
    for(int i=0; i<word.length(); i++) {
        if(temp->contains(word[i])) {
            temp = temp->getNext(word[i]);
        }
        else {
            return false;
        }
    }
    return temp->isFlagSet();
}

bool startWith(string word) {
    Node* temp = root;
    for(int i=0; i<word.size(); i++) {
        if(temp->contains(word[i])) {
            temp = temp->getNext(word[i]);
        }
        else {
            return false;
        }
    }
    return true;
}

signed main(){
    
    return 0;
}