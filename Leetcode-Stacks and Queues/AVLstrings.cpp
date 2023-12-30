#include <iostream>
#include <string>
using namespace std;

class AVLtree
{
public:
    struct Node
    {
        string data;
        Node *left;
        Node *right;
        int height;
    };
    Node *root;

    Node *insertElement(const string &name, Node *root);
    Node *SingleRotationwithLeft(Node *k1);
    Node *SingleRotationwithRight(Node *k2);
    Node *DoubleRotatewithLeft(Node *k3);
    Node *DoubleRotatewithRight(Node *k1);
    int Height(Node *P);
    void PrintInorder(Node *root);
};

int AVLtree::Height(Node *pos)
{
    if (pos == NULL)
    {
        return -1;
    }
    else
        return pos->height;
}

AVLtree::Node *AVLtree::insertElement(const string &name, AVLtree::Node *root)
{
    Node *newNode = new Node;
    newNode->data = name;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
    {
        newNode->height = 0;
        root = newNode;
    }
    else if (name < root->data)
    {
        root->left = insertElement(name, root->left);
        if (Height(root->left) - Height(root->right) == 2)
        {
            if (name < root->left->data)
            {
                root = SingleRotationwithLeft(root);
            }
            else
                root = DoubleRotatewithLeft(root);
        }
    }
    else if (name > root->data)
    {
        root->right = insertElement(name, root->right);
        if (Height(root->right) - Height(root->left) == 2)
        {
            if (name > root->right->data)
            {
                root = SingleRotationwithRight(root);
            }
            else
                root = DoubleRotatewithRight(root);
        }
    }
    root->height = 1 + max(Height(root->left), Height(root->right));
    return root;
}

AVLtree::Node *AVLtree::SingleRotationwithLeft(AVLtree::Node *k1)
{
    Node *k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = 1 + max(Height(k1->left), Height(k1->right));
    k2->height = 1 + max(Height(k2->left), k1->height);
    return k2;
}

AVLtree::Node *AVLtree::SingleRotationwithRight(AVLtree::Node *k2)
{
    Node *k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = 1 + max(Height(k2->left), Height(k2->right));
    k1->height = 1 + max(Height(k1->right), k2->height);
    return k1;
}

AVLtree::Node *AVLtree::DoubleRotatewithLeft(Node *k3)
{
    k3->left = SingleRotationwithRight(k3->left);
    return SingleRotationwithLeft(k3);
}

AVLtree::Node *AVLtree::DoubleRotatewithRight(Node *k1)
{
    k1->right = SingleRotationwithLeft(k1->right);
    return SingleRotationwithRight(k1);
}

void AVLtree::PrintInorder(AVLtree::Node *root)
{
    if (root != NULL)
    {
        PrintInorder(root->left);
        cout << root->data << " ";
        PrintInorder(root->right);
    }
}

int main()
{
    AVLtree avl;
    avl.root = NULL;
    avl.root = avl.insertElement("Osama", avl.root);
    avl.root = avl.insertElement("Haris", avl.root);
    avl.root = avl.insertElement("Alina", avl.root);
    avl.root = avl.insertElement("Zia", avl.root);
    avl.root = avl.insertElement("Nida", avl.root);
    avl.root = avl.insertElement("Saba", avl.root);
    avl.root = avl.insertElement("Yahya", avl.root);
    avl.root = avl.insertElement("Tayo", avl.root);
    avl.root = avl.insertElement("Tom", avl.root);
    avl.root = avl.insertElement("Jim", avl.root);

    cout << "Inorder Traversal:\n ";
    avl.PrintInorder(avl.root);

    return 0;
}
