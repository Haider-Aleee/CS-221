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
    int num;
    char choice;
    list1.AddNodeAtTail(2);
    list1.AddNodeAtTail(4);
    list1.AddNodeAtTail(6);
    cout<<"Linked List 1 is: "<<endl;
    list1.DisplayList();
    cout<<endl;
    do
    {
        cout<<"Enter a node to delete:\n";
        cin>>num;
        list1.DeleteNode(num);
        cout<<endl;
        cout<<"List 1 after deletion is:\n";
        list1.DisplayList();
        cout<<endl;
        cout<<"Do you want to delete another node?(Y/N)\n";
        cin>>choice;
    } while (choice== 'Y' || choice == 'y');
    
   return 0;
}