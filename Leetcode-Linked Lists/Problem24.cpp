//Swap nodes in pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; //If there are less than 2 nodes in the given nodes, then no need to do anything just return the list as it is.
		
        ListNode* dummyNode = new ListNode();
        
        ListNode* prevNode=dummyNode;
        ListNode* currNode=head;
        
        while(currNode && currNode->next){
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        head=dummyNode->next;
        delete dummyNode;
        return head;
    }
};*/


//------------------OOOOOOOOOOOORRRRRRRRRRRRRRRRRRRR--------------------------------

#include <iostream>
using namespace std;
class List
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head=NULL;

    public:
    void AddNodeintheList(int val);
    void PrintList();
    void SwapNodes();
};

void List::AddNodeintheList(int val)
{
    Node* newNode= new Node;
    Node*temp=head;
    newNode->data=val;
    if (head==NULL)
    {
        head=newNode;
        newNode->next=NULL;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
}

void List::PrintList()
{
    Node*temp=head;
    if (head==NULL)
    {
        cout<<"List is empty:\n";
        return;
    }
    while (temp!=NULL)
    {
        cout<<temp->data<<"-";
        temp=temp->next;
    }
}

void List::SwapNodes()
{
    if (!head || !head->next)
    {
        cout<<"Nodes are less than 2 so they cannot be swapped;\n";
        return;
    }
    Node* current=head;
    Node* dummyNode= new Node;
    Node* prev=dummyNode;
    while (current && current->next)
    {
        prev->next=current->next;
        current->next= prev->next->next;
        prev->next->next=current;
        prev=current;
        current=current->next;
    }
    head=dummyNode->next;
    delete dummyNode;
}

int main()
{
    List list;
    list.AddNodeintheList(1);
    list.AddNodeintheList(2);
    list.AddNodeintheList(3);
    list.AddNodeintheList(4);
    list.AddNodeintheList(5);
    list.AddNodeintheList(6);
    list.AddNodeintheList(7);
    cout<<"Initial List is: ";
    list.PrintList();
    cout<<endl;
    list.SwapNodes();
    cout<<"After Swapping, List is: ";
    list.PrintList();
    return 0;
}
