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
    void AddNodeAtHead(int val);
	void AddNodeAtTail(int val);
	void DisplayList(void);
	void DeleteNode(int key);
    void MergeSortedLists(const IntList& otherList);
	void DisplaySpecificNode(int key);
    void DeleteNodeByPointer(int key);
	~IntList();
};

void IntList:: AddNodeAtHead(int val)
{
    Node* newPtr= new Node;
    newPtr->data=val;
    newPtr->next= ListHeadPtr;
    ListHeadPtr= newPtr;
}

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
    while (tempPtr->next!=NULL)
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

	if (ptrCurrent == ListHeadPtr) //node to delete is first node
		ListHeadPtr = ListHeadPtr->next;
	else //node to delete is in middle or at end of list
		ptrPrevious->next = ptrCurrent->next;

	delete ptrCurrent;
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

void IntList::DeleteNodeByPointer(int key)
{
    Node *ptrCurrent= ListHeadPtr;

    while (ptrCurrent!=NULL && ptrCurrent->data!=key)
    {
        ptrCurrent=ptrCurrent->next;
    }
    if (ptrCurrent == NULL)
	{
		cout<<"\nElement to delete not found in the list";
		return;
	}

	if (ptrCurrent == ListHeadPtr) //node to delete is first node
		ListHeadPtr = ListHeadPtr->next;
    else
    {
        ptrCurrent->data= ptrCurrent->next->data;
        ptrCurrent->next= ptrCurrent->next->next;
    }
    ptrCurrent= ptrCurrent->next;
    delete ptrCurrent;
}

int main()
{
    IntList list1,list2;
	list1.AddNodeAtTail(20);
	list1.AddNodeAtTail(10);
	list1.AddNodeAtTail(34);
	list1.AddNodeAtTail(12);
	list1.DeleteNodeByPointer(10);
	cout<<"\nList1 after perorming few operations:";
	list1.DisplayList();
	
	/*list2.AddNodeAtTail(23);
	list2.AddNodeAtHead(45);
	list2.AddNodeAtHead(75);
	list2.AddNodeAtTail(29);
	list2.DeleteNode(45);
	cout<<"\nlist2 after perorming few operations:";
	list2.DisplayList();*/

    return 0;
}