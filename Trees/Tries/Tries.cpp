#include "Tries.hpp"
#include <iostream>

using namespace std;

void Tries::insert(const string& word){
    TrieNode* current = root; // start at root
    for (char c : word){
        if (current->child[c - 'a'] == nullptr){
            TrieNode* newChild = new TrieNode();
            current->child[c - 'a'] = newChild; 
        }
        current = current->child[c - 'a']; // point to the new child, aka new starting
        // this loops over every character in the word
    }
    current->wordEnd = true; // done with all characters, makes the checker true for word at the end mark
}

bool Tries::search( const string& word){
    TrieNode* current = root;
    for (char c : word){
        if (current->child[c - 'a'] == nullptr) return false;
        current = current->child[c- 'a'];
    }
    return current->wordEnd;
}

bool Tries::remover (TrieNode* node, const string& word, int depth){
    if(!node) return false;

    // base case: we are at the end of the word
    if (depth == word.size()){
        if (!node->wordEnd) return false;
        node->wordEnd = false;

        for (int i = 0; i < 26; i++){
            if (node->child[i]) return false; // not deletable since it is a part of another word
        }
        
        return true;
    }

    // recursive case:
    int index = word[depth] - 'a';
    if (remover(node->child[index], word, depth+1)){
        delete node->child[index];
        node->child[index] = nullptr;

        // check if the node is deletable
        if(!node->wordEnd){
            for (int i = 0; i < 26; i++){
                if(node->child[i]) return false;
            }
            return true;
        }
    }
    return false;
}

void Tries::remove(const string& word){
    remover(root, word, 0);
}

void Tries::deleteAllNode(TrieNode* node){
    if(!node) return;
    for(int i = 0; i < 26; i++){
        if(node->child[i]) deleteAllNode(node->child[i]);
    }
    delete node;
}