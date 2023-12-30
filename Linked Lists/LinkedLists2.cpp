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
    while (tempPtr!=NULL)
    {
        cout<<tempPtr->data<<" , ";
        tempPtr=tempPtr->next;
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
        Node* nodeToDelete = ptrCurrent->next;
        ptrCurrent->next = ptrCurrent->next->next;
        delete nodeToDelete;
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
    IntList list1;
	list1.AddNodeAtTail(20);
	list1.AddNodeAtTail(10);
	list1.AddNodeAtTail(34);
	list1.AddNodeAtTail(12);
	list1.DeleteNodeByPointer(10);
	cout<<"\nList1 after perorming few operations:";
	list1.DisplayList();
    return 0;
}