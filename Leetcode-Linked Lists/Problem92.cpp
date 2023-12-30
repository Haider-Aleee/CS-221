//Reverse Linked List Part-2 (reverse a sublist of linked list)

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // If the sublist has only one node, no reversal is needed
        if (left == right) {
            return head;
        }

        // Create a dummy node to simplify handling the case where the reversal starts from the beginning
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Move to the node before the sublist to be reversed
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // Initialize pointers for the reversal process
        ListNode* current = prev->next;
        ListNode* next = nullptr;

        // Reverse the sublist from left to right
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* temp = current->next;
            current->next = next;
            next = current;
            current = temp;
        }

        // Connect the reversed sublist back to the original list
        prev->next->next = current;
        prev->next = next;

        // Return the modified list (dummy->next is the new head if the reversal starts from the beginning)
        return dummy->next;
    }
};*/


//----------------------OOOOOOOOOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRRRRRR------------------------------

#include <iostream>
#include <vector>

using namespace std;

class List
{
public:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head = nullptr;

    void AddNodeintheList(int val);
    void PrintList();
    Node* reverseSublist(Node* head, int left, int right);
    
};

void List::AddNodeintheList(int val)
{
    Node* newNode = new Node;
    Node* temp = head;
    newNode->data = val;
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
}

void List::PrintList()
{
    Node* temp = head;
    if (head == nullptr)
    {
        cout << "List is empty:\n";
        return;
    }
    while (temp != nullptr)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
}

List::Node*List::reverseSublist(List::Node* head, int left, int right)
{
    if (left==right)
    {
        return head;
    }
    Node* dummyNode= new Node;
    dummyNode->next=head;
    Node* prev=dummyNode;
    for (int i = 0; i < left-1; i++)
    {
        prev=prev->next;
    }
    Node*curr=prev->next;
    Node* nxt=NULL;
    for (int i = 0; i < right-left+1; i++)
    {
        Node*temp= curr->next;
        curr->next=nxt;
        nxt=curr;
        curr=temp;
    }
    prev->next->next=curr;
    prev->next=nxt;
    head=dummyNode->next;
    delete dummyNode;
    return head;
}

int main()
{
    List myList;
    myList.AddNodeintheList(1);
    myList.AddNodeintheList(2);
    myList.AddNodeintheList(3);
    myList.AddNodeintheList(4);
    myList.AddNodeintheList(5);
    myList.AddNodeintheList(6);
    myList.AddNodeintheList(7);
    myList.AddNodeintheList(8);

    cout << "Original List: ";
    myList.PrintList();
    cout<<endl;
    int left=2;
    int right=6;
    myList.head=myList.reverseSublist(myList.head, left, right);
    cout<<"After reversing sublist is: \n";
    myList.PrintList();
    return 0;
}