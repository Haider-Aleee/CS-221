// Swap Nodes in K Groups

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
    int length(ListNode* head){
        int count=0;
        while(head){
            count++;
            head= head->next;
        }
        return count;
    }

    ListNode*solve(ListNode*head, int k, int size){
        int count = 0;
        ListNode* curr = head, * prev = NULL,* nxt = NULL;
        while(count < k && curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        size -= k;

        if(nxt && size >= k){
            head->next = solve(nxt , k, size);
        }
        else head->next = nxt;
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k, length(head));
    }
};*/


//-----------------OOOOOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR------------------------

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
    int Length(Node* node);
    Node* SwapKGroups(Node*head, int k);
    Node* Solve(Node* head, int k, int size);
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

int List::Length(Node* head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

List::Node* List::Solve(Node* head, int k, int size)
{
    int count = 0;
    Node* curr = head, * prev = nullptr, * nxt = nullptr;
    while (count < k && curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    size -= k;

    if (nxt && size >= k)
    {
        head->next = Solve(nxt, k, size);
    }
    else
    {
        head->next = nxt;
    }
    return prev;
}

List::Node* List::SwapKGroups(Node* head, int k)
{
    head = Solve(head, k, List::Length(head));
}

int main()
{
    List myList;

    // Example: Add nodes to the list
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

    int k = 3; // Specify the value of k

    myList.head = myList.SwapKGroups(myList.head, k);

    cout << "\nList after swapping in groups of " << k << ": ";
    myList.PrintList();

    return 0;
}
