#include "nodeTrie.h"

class trie {
    public:
        trie();
        void insert(string word);
        bool search(string word);
    private:
        nodeTrie *root;
};

trie :: trie () {
    root = new nodeTrie('\0', nullptr);
}

void trie :: insert(string word) {
    nodeTrie *curr = root;

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        nodeTrie *sub = curr->getChild(c);

        if (sub != nullptr) {
            curr = sub;
        }
        else {
            curr = curr->addChild(new nodeTrie(c, curr));
        }
        if (i = word.length() - 1) {
            curr->setEnd(true);
        }
    }
}

// Complejidad: O(n) n == tamaño de la palabra
bool trie :: search(string word) {
    nodeTrie *curr = root;

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        curr = curr->getChild(c);

        if (curr == nullptr) {
            return false;
        }
    }

    return curr->getEnd();
}

