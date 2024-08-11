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
void inorder(Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
int inorder_successor(Tree *root, int val)
{
    Tree *current = root;
    Tree *successor = nullptr;
    while (current)
    {
        if (current->val > val)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return successor ? successor->val : -1;
}
int inorder_predecessor(Tree *root, int val)
{
    Tree *current = root;
    Tree *predecessor = nullptr;

    while (current)
    {
        if (current->val < val)
        {
            predecessor = current;
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return predecessor ? predecessor->val : -1;
}
Tree *minValueNode(Tree *node)
{
    Tree *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}
Tree *deleteNode(Tree *root, int key)
{
    if (!root)
        return root;

    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (!root->left)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        Tree *temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
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
int solve(Tree *root, int k, int &count)
{
    if (root == nullptr)
    {
        return -1;
    }
    int left = solve(root->left, k, count);
    if (left != -1)
    {
        return left;
    }
    count++;
    if (count == k)
    {
        return root->val;
    }
    return solve(root->right, k, count);
}
int kthSmallest(Tree *root, int k)
{
    int count = 0;
    return solve(root, k, count);
}
int countNodesInRange(Tree *root, int low, int high)
{
    if (!root)
        return 0;
    if (root->val >= low && root->val <= high)
    {
        return 1 + countNodesInRange(root->left, low, high) + countNodesInRange(root->right, low, high);
    }
    else if (root->val < low)
    {
        return countNodesInRange(root->right, low, high);
    }
    else
    {
        return countNodesInRange(root->left, low, high);
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
    cout << "\ninorder traversal:" << endl;
    inorder(root);
    int low = 5;
    int high = 15;
    int count = countNodesInRange(root, low, high);
    cout << "Number of nodes in the range [" << low << ", " << high << "]: " << count << endl;
    int smallest = kthSmallest(root, 4);
    cout << "\nkth smallest element, let k=4 " << smallest << endl;
    int value = 6;
    int successor = inorder_successor(root, value);
    int predecessor = inorder_predecessor(root, value);
    cout << "\nInorder successor of " << value << " is: " << successor << endl;
    cout << "Inorder predecessor of " << value << " is: " << predecessor << endl;
    int value_to_delete = 6;

    root = deleteNode(root, value_to_delete);

    cout << "\nBST after deleting " << value_to_delete << ":" << endl;
    display(root);
    return 0;
}
