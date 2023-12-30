// Remove Duplicates from a sorted list Part-2

/*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != nullptr) {
            bool duplicateFound = false;

            while (current->next != nullptr && current->val == current->next->val) {
                // Skip all consecutive duplicates
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                duplicateFound = true;
            }

            if (duplicateFound) {
                // Skip the last duplicate
                ListNode* temp = current;
                prev->next=current->next;
                current = current->next;
                delete temp;
            } else {
                // No duplicate, move to the next node
                prev->next = current;
                prev = prev->next;
                current = current->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};*/

//---------------------OR---------------------------------------------

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
    ListNode* deleteDuplicates(ListNode* head) {
            if (!head || !head->next)
            return head;

        ListNode* temp = head;
        ListNode* prev=NULL;
        map<int, int> mp;

        while (temp) {
            mp[temp->val]++;
            temp = temp->next;
        }

        temp = head;
        while (temp && head) 
        {
            if (mp[temp->val] > 1)
            {
                if(prev==NULL)
                {
                    head=head->next;
                    temp=temp->next;
                }
                else{
                    prev->next=temp->next;
                    temp=temp->next;   
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
               
            
        }

        return head;    
    }
};*/


//---------------------------OOOOOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRR---------------------------------------

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
    Node* deleteDuplicates(Node* head);
    
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
List::Node* List::deleteDuplicates(List::Node*head)
{
    Node* dummyNode= new Node;
    dummyNode->next=head;
    Node* prev=dummyNode;
    Node* curr=head;
    while (curr!=NULL)
    {
        bool duplicateFound=false;
        while (curr->next!=NULL && curr->data==curr->next->data)
        {
            Node* temp=curr->next;
            curr->next=curr->next->next;
            //curr->next->next=NULL;
            delete temp;
            duplicateFound=true;
        }
        if (duplicateFound)
        {
            Node* temp=curr;
            //prev->next=curr->next;
            curr=curr->next;
            //temp->next=NULL;
            delete temp;
        }
        else
        {
            prev->next=curr;
            prev=prev->next;
            curr=curr->next;
        }
    }
    head=dummyNode->next;
    delete dummyNode;
    return head;
}

int main()
{
    List myList;
    myList.AddNodeintheList(1);
    myList.AddNodeintheList(2);
    myList.AddNodeintheList(2);
    myList.AddNodeintheList(4);
    myList.AddNodeintheList(5);
    myList.AddNodeintheList(6);
    myList.AddNodeintheList(6);
    myList.AddNodeintheList(8);

    cout << "Original List: ";
    myList.PrintList();
    cout<<endl;
    myList.head=myList.deleteDuplicates(myList.head);
    cout<<"List after deleting duplicates is: \n";
    myList.PrintList();
    return 0;
}