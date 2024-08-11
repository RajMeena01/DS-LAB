#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TSTNode {
    char data;
    bool isEndOfWord;
    TSTNode *left, *middle, *right;
    
    TSTNode(char ch) : data(ch), isEndOfWord(false), left(nullptr), middle(nullptr), right(nullptr) {}
};

class TST {
private:
    TSTNode* root;

    // Helper function to insert a word into the TST
    TSTNode* insert(TSTNode* node, const string& word, int index) {
        if (node == nullptr) {
            node = new TSTNode(word[index]);
        }
        
        if (word[index] < node->data) {
            node->left = insert(node->left, word, index);
        } else if (word[index] > node->data) {
            node->right = insert(node->right, word, index);
        } else {
            if (index + 1 < word.size()) {
                node->middle = insert(node->middle, word, index + 1);
            } else {
                node->isEndOfWord = true;
            }
        }
        
        return node;
    }

    // Helper function to search for a word in the TST
    bool search(TSTNode* node, const string& word, int index) const {
        if (node == nullptr) {
            return false;
        }
        
        if (word[index] < node->data) {
            return search(node->left, word, index);
        } else if (word[index] > node->data) {
            return search(node->right, word, index);
        } else {
            if (index + 1 == word.size()) {
                return node->isEndOfWord;
            }
            return search(node->middle, word, index + 1);
        }
    }

    // Helper function to perform prefix search in the TST
    void collect(TSTNode* node, string prefix, vector<string>& results) const {
        if (node == nullptr) {
            return;
        }

        collect(node->left, prefix, results);

        if (node->isEndOfWord) {
            results.push_back(prefix + node->data);
        }

        collect(node->middle, prefix + node->data, results);

        collect(node->right, prefix, results);
    }

    // Helper function to find the node representing the last character of the prefix
    TSTNode* findNode(TSTNode* node, const string& prefix, int index) const {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (prefix[index] < node->data) {
            return findNode(node->left, prefix, index);
        } else if (prefix[index] > node->data) {
            return findNode(node->right, prefix, index);
        } else {
            if (index + 1 == prefix.size()) {
                return node;
            }
            return findNode(node->middle, prefix, index + 1);
        }
    }

public:
    TST() : root(nullptr) {}

    void insert(const string& word) {
        if (!word.empty()) {
            root = insert(root, word, 0);
        }
    }

    bool search(const string& word) const {
        if (word.empty()) {
            return false;
        }
        return search(root, word, 0);
    }

    vector<string> prefixSearch(const string& prefix) const {
        vector<string> results;
        TSTNode* node = findNode(root, prefix, 0);
        if (node == nullptr) {
            return results;
        }

        if (node->isEndOfWord) {
            results.push_back(prefix);
        }
        collect(node->middle, prefix, results);

        return results;
    }

    vector<string> autoComplete(const string& prefix) const {
        return prefixSearch(prefix);
    }
};

// Example usage
int main() {
    TST tst;
    tst.insert("apple");
    tst.insert("app");
    tst.insert("apricot");
    tst.insert("banana");
    tst.insert("bat");
    tst.insert("ball");
    tst.insert("cat");

    cout << "Search 'app': " << (tst.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (tst.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'cap': " << (tst.search("cap") ? "Found" : "Not Found") << endl;

    vector<string> results = tst.autoComplete("ba");
    cout << "Auto-complete for 'ba':" << endl;
    for (const string& word : results) {
        cout << word << endl;
    }

    return 0;
}
