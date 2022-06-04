#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
struct node *newNode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << "->";
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "->";
    inorder(root->left);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << "->";
}
struct node *min(struct node *root)
{
    struct node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(struct node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh + rh, max(ld, rd));
}
struct node *deletenode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = min(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}
int left_height(node *root)
{
    int ht = 0;
    while (root)
    {
        ht++;
        root = root->left;
    }
    return ht;
}

// Function to get the right height
// of the binary tree
int right_height(node *root)
{
    int ht = 0;
    while (root)
    {
        ht++;
        root = root->right;
    }
    // Return the right height obtained
    return ht;
}
int numnodes(struct node *root)
{
    if (root == NULL)
        return 0;
    int lh = left_height(root);
    int rh = right_height(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return (1 + numnodes(root->left) + numnodes(root->right));
}
int main()
{
    node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << "\nDiameter: " << diameter(root);
    cout << "\nNum nodes: " << numnodes(root);
    cout << "\nHeight: " << height(root) << endl;
    deletenode(root, 3);
    deletenode(root, 1);
    deletenode(root, 6);
    inorder(root);
    cout << "\nHeight: " << height(root) << endl;
    return 0;
}