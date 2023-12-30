#include <iostream>
using namespace std;

class IntList
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* ListHeadPtr;
    public:
    
    IntList()
    {
        ListHeadPtr=NULL;
    }

	void AddNodeAtTail(int val);
	void DisplayList(void);
	void DeleteNode(int key);
    void MergeSortedLists(const IntList& otherList);
	~IntList();
};

void IntList::AddNodeAtTail(int val)
{
    Node* newPtr= new Node;
    Node* ptrTemp= ListHeadPtr;
    newPtr->data=val;
    newPtr->next= NULL;
    if (ListHeadPtr==NULL)
    {
        ListHeadPtr=newPtr;
        return;
    }
    while (ptrTemp->next!=NULL)
    {
        ptrTemp= ptrTemp->next;
    }
    ptrTemp->next=newPtr;
}

void IntList::DisplayList(void)
{
    Node* tempPtr= ListHeadPtr;
    cout<<endl;
    while (tempPtr!=NULL)
    {
        cout<<tempPtr->data<<" , ";
        tempPtr=tempPtr->next;
    }
}

void IntList::DeleteNode(int key)
{
    Node *ptrCurrent=ListHeadPtr,*ptrPrevious;

	while (ptrCurrent!=NULL && ptrCurrent->data!=key)
	{
		ptrPrevious = ptrCurrent;
		ptrCurrent = ptrCurrent->next;
	}

	if (ptrCurrent == NULL)
	{
		cout<<"\nElement to delete not found in the list";
		return;
	}

	if (ptrCurrent == ListHeadPtr) 
		ListHeadPtr = ListHeadPtr->next;
	else 
		ptrPrevious->next = ptrCurrent->next;

	delete ptrCurrent;
}

void IntList::MergeSortedLists(const IntList& otherList)
{
    Node* mergedList = NULL;
    Node* current1 = this->ListHeadPtr;
    Node* current2 = otherList.ListHeadPtr;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data < current2->data)
        {
            if (mergedList == NULL)
            {
                mergedList = new Node;
                mergedList->data = current1->data;
                mergedList->next = NULL;
                this->ListHeadPtr = mergedList;
            }
            else
            {
                mergedList->next = new Node;
                mergedList = mergedList->next;
                mergedList->data = current1->data;
                mergedList->next = NULL;
            }
            current1 = current1->next;
        }
        else
        {
            if (mergedList == NULL)
            {
                mergedList = new Node;
                mergedList->data = current2->data;
                mergedList->next = NULL;
                this->ListHeadPtr = mergedList;
            }
            else
            {
                mergedList->next = new Node;
                mergedList = mergedList->next;
                mergedList->data = current2->data;
                mergedList->next = NULL;
            }
            current2 = current2->next;
        }
    }

    // If there are remaining nodes in the first list
    while (current1 != NULL)
    {
        mergedList->next = new Node;
        mergedList = mergedList->next;
        mergedList->data = current1->data;
        mergedList->next = NULL;
        current1 = current1->next;
    }

    // If there are remaining nodes in the second list
    while (current2 != NULL)
    {
        mergedList->next = new Node;
        mergedList = mergedList->next;
        mergedList->data = current2->data;
        mergedList->next = NULL;
        current2 = current2->next;
    }
}


IntList::~IntList()
{
	Node *ptrPrevious;	
	while (ListHeadPtr!=NULL)
	{
		ptrPrevious = ListHeadPtr;
		ListHeadPtr= ListHeadPtr->next;
		delete ptrPrevious;
	}
}

int main()
{
    IntList list1, list2;
    list1.AddNodeAtTail(2);
    list1.AddNodeAtTail(4);
    list1.AddNodeAtTail(6);
    cout<<"Given Linked List 1 is: "<<endl;
    list1.DisplayList();
    cout<<endl;
   
   list2.AddNodeAtTail(1);
    list2.AddNodeAtTail(3);
    list2.AddNodeAtTail(5);
    list2.AddNodeAtTail(7);
    cout<<"Given Linked List 2 is: "<<endl;
    list2.DisplayList();
    cout<<endl;

    list1.MergeSortedLists(list2);
    cout<<"Merged List is: "<<endl;
    list1.DisplayList();
    return 0;
}