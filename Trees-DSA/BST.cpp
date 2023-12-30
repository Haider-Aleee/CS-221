
/*#include <iostream>
#include<climits>
using namespace std;

class BST
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };
    Node *root = NULL;

    void insertion(int val);
    bool validBST(Node *root);
};

void BST::insertion(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data > val)
        {
            if (temp->left)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = newNode;
                break;
            }
        }
        else if (temp->data < val)
        {
            if (temp->right)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = newNode;
                break;
            }
        }
        else
        {
            cout << "Duplicate value found\n";
            break;
        }
    }
}

bool isValidBSTUtil(BST::Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data > minValue && root->data < maxValue &&
        isValidBSTUtil(root->left, minValue, root->data) &&
        isValidBSTUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BST::validBST(Node *root)
{
    // The initial call to isValidBSTUtil with INT_MIN and INT_MAX represents negative and positive infinity.
    return isValidBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    BST myTree;
    myTree.insertion(5);
    myTree.insertion(1);
    myTree.insertion(4);
    myTree.insertion(3);
    myTree.insertion(6);

    bool ans = myTree.validBST(myTree.root);

    if (ans)
    {
        cout << "Valid BST;\n";
    }
    else
    {
        cout << "Invalid BST:\n";
    }

    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int countContinuousSubarrays(const vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    // Create a deque to store indices of elements in the current window
    deque<int> dq;

    for (int i = 0; i < n; ++i) {
        // Remove elements from the front of the deque that are out of the current window
        while (!dq.empty() && nums[i] - nums[dq.front()] > 2) {
            dq.pop_front();
        }

        // Add the current index to the back of the deque
        dq.push_back(i);

        // Count subarrays formed by elements in the current window
        count += i - dq.front() + 1;

        // Remove elements from the back of the deque that violate the condition
        while (!dq.empty() && nums[dq.back()] - nums[dq.front()] > 2) {
            dq.pop_front();
        }
    }

    return count;
}

int main() {
    vector<int> nums = {5, 4, 2, 4};
    int result = countContinuousSubarrays(nums);

    cout << "Total continuous subarrays: " << result << endl;

    return 0;
}*/

#include <iostream>
#include <string>
using namespace std;

class BinarySearchTree
{
public:
    struct Node
    {
        string data;
        Node *left;
        Node *right;

        Node(const string &value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

    BinarySearchTree() : root(nullptr) {}

    void insert(const string &value, Node *&currentRoot)
    {
        if (currentRoot == nullptr)
        {
            currentRoot = new Node(value);
        }
        else if (value < currentRoot->data)
        {
            insert(value, currentRoot->left);
        }
        else if (value > currentRoot->data)
        {
            insert(value, currentRoot->right);
        }
    }

    void insert(const string &value)
    {
        insert(value, root);
    }
    void printInorder(Node* root)
    {
        if (root!=NULL)
        {
            printInorder(root->left);
            cout<<root->data<<"->";
            printInorder(root->right);
        }
        
    }
    void removeNode(const string& value)
    {
        deleteNode(value, root);
    }
    void deleteNode(const string& value, Node*&currentNode)
    {
        if (value<currentNode->data)
        {
            deleteNode(value, currentNode->left);
        }
        else if (value >currentNode->data)
        {
            deleteNode(value, currentNode->right);
        }
        else 
        makeDeletion(value, currentNode);
    }
    void makeDeletion(const string& value, Node*& currentNode)
    {
        Node* temp;
        if (currentNode==nullptr)
        {
            cout<<"Cannot delete empty node:\n";
            return;
        }
        else if (currentNode->left==nullptr)
        {
            temp=currentNode;
            currentNode=currentNode->right;
            delete temp;
        }
        else if(currentNode->right==nullptr)
        {
            temp=currentNode;
            currentNode=currentNode->left;
            delete temp;
        }
        else 
        {
            temp=currentNode->right;
            while (temp->left)
            {
                temp=temp->left;
            }
            
            temp->left=currentNode->left;
            temp=currentNode;
            currentNode=currentNode->right;
            delete temp;
        }
    }
};

int main()
{
    BinarySearchTree bst;

    // Insert strings into the Binary Search Tree
    bst.insert("Osama");
    bst.insert("Haris");
    bst.insert("Alina");
    bst.insert("Zia");
    bst.insert("Nida");
    bst.insert("Saba");
    bst.insert("Yahya");
    bst.insert("Tayo");
    bst.insert("Tom");
    bst.insert("Jim");

    // Printing the Binary Search Tree (Inorder traversal)
    cout << "Inorder Traversal of the Binary Search Tree: \n";
    bst.printInorder(bst.root);

    cout<<"After Removing Osama:\n";
    bst.removeNode("Osama");
    bst.printInorder(bst.root);
    return 0;
}
