// Merge Two Sorted Linked Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        
        //when both list1 and list2 isn't empty
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        
        // we reached at the end of one of the list
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        
        return dummy->next;
    }
};*/

//--------------------OOOOOOOOOOORRRRRRRRRRRRRRRRRRRRR--------------------------------------------

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
    void MergeSortedLists(List* List1, List* List2);
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

void List::MergeSortedLists(List *List1, List *List2)
{
    Node* dummyNode= new Node;
    Node* temp;
    temp=dummyNode;
    Node* list1=List1->head;
    Node*list2=List2->head;
    while (list1 && list2)
    {
        if (list1->data<list2->data)
        {
            temp->next=list1;
            list1=list1->next;
        }
        else if (list1->data > list2->data)
        {
            temp->next=list2;
            list2=list2->next;
        }
        temp = temp->next;
    }
    if (list1)
    {
        temp->next=list1;
    }
    if (list2)
    {
        temp->next=list2;
    }
    head=dummyNode->next;
    delete dummyNode;
}

int main()
{
    List list1, list2;
    list1.AddNodeintheList(2);
    list1.AddNodeintheList(4);
    list1.AddNodeintheList(6);
    list1.AddNodeintheList(8);
    cout<<"List 1 is: ";
    list1.PrintList();
    cout<<endl;

    list2.AddNodeintheList(1);
    list2.AddNodeintheList(3);
    list2.AddNodeintheList(5);
    list2.AddNodeintheList(7);
    list2.AddNodeintheList(9);
    cout<<"List 2 is: ";
    list2.PrintList();
    cout<<endl;

    List list3;
    list3.MergeSortedLists(&list1,&list2);
    cout<<"Merged List is: ";
    list3.PrintList();
    return 0;
}