#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class BST
{
    public:
    struct Node
    {
        int data;
        Node*left;
        Node*right;
    };
    Node*root=NULL;

    void Insertion(int val)
    {
        Node*newNode= new Node;
        newNode->data=val;
        newNode->left=NULL;
        newNode->right=NULL;
        if (root==NULL)
        {
            root=newNode;
            return;
        }
        Node*temp=root;
        while (temp!=NULL)
        {
            if (val<temp->data)
            {
                if (temp->left)
                {
                    temp=temp->left;
                }
                else
                {
                    temp->left=newNode;
                    break;
                }
            }
            else if (val>temp->data)
            {
                if (temp->right)
                {
                    temp=temp->right;
                }
                else
                {
                    temp->right=newNode;
                    break;
                }
            }
            else
            {
                return;
            }
        }
    }
    vector<int> diagonalTrav(Node*root)
    {
        vector<int>output;
        if (!root)
        {
            return output;
        }
        queue<Node*>st;
        st.push(root);
        while (!st.empty())
        {
            Node*current=st.front();
            st.pop();
            while (current)
            {
                output.push_back(current->data);
                if (current->left)
                {
                    st.push(current->left);
                }
                current=current->right;
            }
            
        }
        
        return output;
    }
    void deletion(int num)
    {
        deleteNode(num,root);
    }
    void deleteNode(int num, Node*& nodePtr)
    {
        if (num<nodePtr->data)
        {
            deleteNode(num,nodePtr->left);
        }
        else if (num>nodePtr->data)
        {
            deleteNode(num, nodePtr->right);
        }
        else
        makeDeletion(nodePtr);
    }
    void makeDeletion(Node*& nodePtr)
    {
        Node*tempNode;
        if (nodePtr==NULL)
        {
            cout<<"cannot delete empty Node:\n";
        }
        else if (nodePtr->right==NULL)
        {
            tempNode=nodePtr;
            nodePtr=nodePtr->left;
            delete tempNode;
        }
        else if (nodePtr->left==NULL)
        {
            tempNode=nodePtr;
            nodePtr=nodePtr->right;
            delete tempNode;
        }
        else
        {
            tempNode=nodePtr->right;
            while (tempNode->left)
            {
                tempNode=tempNode->left;
            }
            tempNode->left=nodePtr->left;
            tempNode=nodePtr;
            nodePtr=nodePtr->right;
            delete tempNode;
        }
    }
};
int main()
{
    BST myTree;
    vector<int>ans;
    myTree.Insertion(6);
    myTree.Insertion(2);
    myTree.Insertion(1);
    myTree.Insertion(9);
    myTree.Insertion(8);
    myTree.Insertion(10);
    myTree.Insertion(7);
    myTree.deletion(1);
    ans=myTree.diagonalTrav(myTree.root);
    for (int num:ans)
    {
        cout<<num<<" ";
    }
    return 0;
}