#include <iostream>
using namespace std;
class AVLtree
{
    public:
    struct Node
    {
        int data;
        Node*left;
        Node* right;
        int height;
    };
    Node*root;
    Node*pos;

    Node* insertElement(int val, Node* root);
    Node*SingleRotationwithLeft(Node* k1);
    Node* SingleRotationwithRight(Node* k2);
    Node* DoubleRotatewithLeft(Node*k3);
    Node* DoubleRotatewithRight(Node* k3);
    int Height(Node* P);
    void PrintInorder(Node*root);
    Node* deleteElement(int val, Node* root);
    Node* findMin(Node* root);
};
int AVLtree::Height(AVLtree::Node* P)
{
    if (P==NULL)
    {
        return -1;
    }
    else
    return P->height;
}
AVLtree::Node* AVLtree::insertElement(int val, AVLtree::Node*root)
{
    Node* newNode=new Node;
    newNode->data=val;
    if (root==NULL)
    {
        newNode->left=NULL;
        newNode->right=NULL;
        newNode->height=0;
        root=newNode;
    }
    else if (val<root->data)
    {
        root->left=insertElement(val, root->left);
        if (Height(root->left)-Height(root->right)==2)
        {
            if (val<root->left->data)
            {
                root=SingleRotationwithLeft(root);
            }
            else
            root=DoubleRotatewithLeft(root);
        }
    }
    else if (val>root->data)
    {
        root->right=insertElement(val,root->right);
        if (Height(root->right)-Height(root->left)==2)
        {
            if (val>root->right->data)
            {
                root=SingleRotationwithRight(root);
            }
            else
            root=DoubleRotatewithRight(root);
        }
    }
    root->height=max(Height(root->left),Height(root->right))+1;
    return root;   
}
AVLtree::Node* AVLtree::SingleRotationwithRight(AVLtree::Node*k1)
{
    Node*k2;
    k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1->height=max(Height(k1->left),Height(k1->right))+1;
    k2->height=max(Height(k2->right),k1->height)+1;
    return k2;
}
AVLtree::Node* AVLtree::SingleRotationwithLeft(AVLtree::Node*k2)
{
    Node*k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(Height(k2->left),Height(k2->right))+1;
    k1->height=max(Height(k1->left),k2->height)+1;
    return k1;
}
AVLtree::Node* AVLtree::DoubleRotatewithLeft(AVLtree::Node*k3)
{
    k3->left=SingleRotationwithRight(k3->left);
    return SingleRotationwithLeft(k3);
}
AVLtree::Node* AVLtree::DoubleRotatewithRight(AVLtree::Node*k1)
{
    k1->right=SingleRotationwithLeft(k1->right);
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

AVLtree::Node* AVLtree::findMin(AVLtree::Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

AVLtree::Node* AVLtree::deleteElement(int val, AVLtree::Node* root) {
    if (root == NULL) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteElement(val, root->left);
    } else if (val > root->data) {
        root->right = deleteElement(val, root->right);
    } else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteElement(temp->data, root->right);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = max(Height(root->left), Height(root->right)) + 1;

    int balance = Height(root->left) - Height(root->right);

    // Perform rotations if needed
    if (balance > 1) {
        if (Height(root->left->left) >= Height(root->left->right)) {
            root = SingleRotationwithLeft(root);
        } else {
            root = DoubleRotatewithLeft(root);
        }
    } else if (balance < -1) {
        if (Height(root->right->right) >= Height(root->right->left)) {
            root = SingleRotationwithRight(root);
        } else {
            root = DoubleRotatewithRight(root);
        }
    }

    return root;
}

int main()
{
    AVLtree avl;
    avl.root = NULL;

    // Insert elements into the AVL tree
    avl.root = avl.insertElement(10, avl.root);
    avl.root = avl.insertElement(20, avl.root);
    avl.root = avl.insertElement(30, avl.root);
    avl.root = avl.insertElement(15, avl.root);
    avl.root = avl.insertElement(5, avl.root);

    // Print the tree in Inorder traversal
    cout << "Inorder Traversal: ";
    avl.PrintInorder(avl.root);
    cout<<endl;
    cout<<"After deleting 20:\n";
    avl.root=avl.deleteElement(20,avl.root);
    avl.PrintInorder(avl.root);
    return 0;
}






