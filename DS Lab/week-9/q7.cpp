#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};
void printPaths(node* root, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i != path.size()-1?"->":"");
        }
        cout << endl;
    } else {
        printPaths(root->left, path);
        printPaths(root->right, path);
    }
    path.pop_back();
}
int main() {
    node * head = new node(5);
    head->left = new node(7);
    head->right = new node(0);
    head->left->left = new node(3);
    head->left->right = new node(12);
    head->right->left = new node(13);
    head->right->right = new node(43);
    vector<int> path;
    printPaths(head, path);
    return 0;
}