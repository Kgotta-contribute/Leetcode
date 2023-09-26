#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : isEnd(false), children(26, nullptr) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << (trie.search("apple") ? "true" : "false") << endl;     // Output: true
    cout << (trie.search("app") ? "true" : "false") << endl;       // Output: false
    cout << (trie.startsWith("app") ? "true" : "false") << endl;   // Output: true
    trie.insert("app");
    cout << (trie.search("app") ? "true" : "false") << endl;       // Output: true

    return 0;
}
