#include <bits/stdc++.h> 

class Node {
    public:
    Node *links [26];
    bool flag;

    bool containsKey (char ch) {
        return (links [ch-'a']!=NULL);
    }

    void put (char ch, Node *node) {
        links [ch-'a'] = node;
    }

    Node *get (char ch) {
        return links[ch-'a'];
    }

    void setEnd () {
        flag = true;
    }

    bool isEnd () {
        return flag;
    }
};


class Trie {
    private:
        Node *root = new Node ();

    public:
        void insert (string word) {
            Node *node = root;
            for (int i=0; i<word.size(); i++) {
                if (!node -> containsKey (word[i])) {
                    node ->put (word[i], new Node());
                }
                node = node -> get(word[i]);
            }
            node -> setEnd();
        }

        bool search(string word) {
            Node *node = root;
            for (int i=0; i<word.length(); i++) {
                if (!node -> containsKey(word[i])) {
                    return false;
                }

                node = node -> get(word[i]);
            }
            return node -> isEnd ();
        }

        bool startsWith(string word) {
            Node *node = root;
            for (int i=0; i<word.length(); i++) {
                if (!node -> containsKey(word[i])) {
                    return false;
                }
                node = node -> get(word[i]);
            }
            return true;
        }

        bool checkIfPrefixExists (string word) {
            Node *node = root;
            bool flag = true;
            for (int i=0; i<word.length(); i++) {
                if (node -> containsKey(word[i])) {
                    node = node -> get (word[i]);
                    if (node -> isEnd()==false) return false;
                }
                else return false;
            }
            return true;
        }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie mahi;
    for (int i=0; i<n; i++) {
        mahi.insert (a[i]);
    }

    string longest = "";
    for (int i=0; i<n; i++) {
        if (mahi.checkIfPrefixExists(a[i])) {
            if (a[i].length() > longest.length()) {
                longest = a[i];
            }

            else if (a[i].length() == longest.length() && a[i]<longest) {
                longest = a[i];
            }   
        }
    }

    if (longest == "") return "None";
    return longest;
}
