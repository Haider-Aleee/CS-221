// Remove nth Node from the end of the Linked List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* temp=head;
        
        int len=0;

        while(temp!=NULL){
            temp=temp->next;
            len++;
        }

        if(n>len){
            return NULL;
        }
        if(len-n==0){
            head=head->next;
            return head;
        }
        struct ListNode* pre=head;
        temp=head;

        for(int i=0;i<len-n;i++){
            pre=temp;
            temp=temp->next;
        }
        pre->next=temp->next;
        return head;
       
    }
};*/

//---------------------OOOOORRRRRRRRRRRRR-------------------

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
    void deleteNthNode(int node);
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

/*void List::deleteNthNode(int node)
{
    int length=0;
    Node*temp=head;
    if (head==NULL)
    {
        cout<<"List is empty!!!\n";
        return;
    }
    
    while (temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    if (node>length)
    {
        cout<<"Node not present in the List...\n";
        return;
    }
    if (length-node==0)
    {
        temp=head;
        head=head->next;
        delete temp;
        cout<<"Remaining List is::: ";
        PrintList();
    }

    Node*prev;
    Node*nodetoDelete;
    temp=head;
    prev=head;
    for (int i = 0; i < length-node; i++)
    {
        prev=temp;
        temp=temp->next;
    }
    nodetoDelete=prev->next;
    prev->next=temp->next;
    nodetoDelete->next=NULL;
    delete nodetoDelete;
    cout<<"Reamining List is: ";
    PrintList();
}*/
void List::deleteNthNode(int n)
{
    int count=0;
    Node*temp=head;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    int size=count;
    Node*curr=head;
    for (int i = 0; i < count-n-1; i++)
    {
        curr=curr->next;
    }
    Node*ptr=curr->next;
    curr->next=curr->next->next;
    ptr->next=NULL;
    delete ptr;
}

int main()
{
    List list;
    int num;
    list.AddNodeintheList(1);
    list.AddNodeintheList(2);
    list.AddNodeintheList(3);
    list.AddNodeintheList(4);
    list.AddNodeintheList(5);
    list.AddNodeintheList(6);
    list.AddNodeintheList(7);
    cout<<"Initial List is: ";
    list.PrintList();
    cout<<"Enter Node number which you want to delete from the end::\n";
    cin>>num;
    cout<<endl;
    list.deleteNthNode(num);
    list.PrintList();
    return 0;
}