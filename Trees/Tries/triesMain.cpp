#include "Tries.hpp"
#include <iostream>
using namespace std;

int main() {
    Tries trie;

    // Insert words into the Trie
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    trie.insert("word");

    // Search for words
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'word': " << (trie.search("word") ? "Found" : "Not Found") << endl;
    cout << "Search 'hi': " << (trie.search("hi") ? "Found" : "Not Found") << endl;
    cout << "Search 'hola': " << (trie.search("hola") ? "Found" : "Not Found") << endl;

    // Delete a word
    trie.remove("hi");
    cout << "After deleting 'hi': " << endl;
    cout << "Search 'hi': " << (trie.search("hi") ? "Found" : "Not Found") << endl;

    // Check other words
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;

    return 0;
}
