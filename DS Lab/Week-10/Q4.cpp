#include <iostream>
#include <queue>
using namespace std;
struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree(int x) : val(x), left(NULL), right(NULL) {}
};
Tree *insertval(Tree *root, int val)
{
    if (!root)
    {
        root = new Tree(val);
    }
    else if (val <= root->val)
    {
        root->left = insertval(root->left, val);
    }
    else
    {
        root->right = insertval(root->right, val);
    }
    return root;
}
Tree *trimBST(Tree *root, int L, int R)
{
    if (!root)
        return nullptr;

    if (root->val < L)
    {
        return trimBST(root->right, L, R);
    }
    else if (root->val > R)
    {
        return trimBST(root->left, L, R);
    }
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}
void display(Tree *root)
{
    if (root == NULL)
        return;
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Tree *current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl;
    }
}
int main()
{
    int elements[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(elements) / sizeof(elements[0]);
    Tree *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insertval(root, elements[i]);
    }
    cout << "BST :" << endl;
    display(root);
    int L = 7;
    int R = 15;
    Tree *trimmedRoot = trimBST(root, L, R);
    cout << "BST after trimming to the range [" << L << ", " << R << "]:" << endl;
    display(trimmedRoot);
    cout << endl;
    return 0;
}
