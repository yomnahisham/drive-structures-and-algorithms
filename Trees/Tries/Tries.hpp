#ifndef Tries_H
#define Tries_H

#include <iostream>

using namespace std;

class Tries{

private:
    struct TrieNode {
        TrieNode* child[26];
        char c;
        bool wordEnd;
        TrieNode(){
            wordEnd = false;
            for (int i = 0; i < 26; i++){
                child[i] = nullptr;
            }
        }
    };
    TrieNode* root;

    void deleteAllNode(TrieNode* node);
    bool remover (TrieNode* node, const string& word, int depth);
    // depth represents the length of the word
    // ex. root
    //      c    depth = 1
    //      a    depth = 2
    //      t    depth = 3

public:
    Tries(){ root = new TrieNode(); }
    ~Tries(){ deleteAllNode(root); }
    void insert (const string& word);
    bool search (const string& word);

    void remove (const string& word);

};



#endif // Tries_H