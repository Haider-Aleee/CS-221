// Merge K Sorted Linked Lists

/*class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {     //if lists are empty then simply return Nullptr
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);   //else call this function
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {         //if vector contains only 1 linked list means k=1
            return lists[start];
        }
        if (start + 1 == end) {     //if k=2 i.e; two linked lists are present in vector then call merge function
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;      //this line determines the middle of given vector so that we can
                                                  split vector into two arrays
        ListNode* left = mergeKListsHelper(lists, start, mid);     //Recursive calls for merging two resultant arrays
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {   //This function is same as merging two linked lists
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }
};*/

//----------------------------OOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRR---------------------------------

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
    Node* head=NULL;
    void AddNodeintheList(int val);
    void PrintList();
    Node*MergeSortedLists(Node* list1, Node* list2);
    void MergeKSortedLists(vector<Node*> &lists);
    Node*MergeKListsHelper(vector<Node*> &lists, int start, int end);
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

List::Node*List::MergeSortedLists(Node *list1, Node *list2)
{
    Node* dummyNode= new Node;
    Node* temp;
    temp=dummyNode;
    //Node* list1=List1->head;
    //Node*list2=List2->head;
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
    return head;
}

void List::MergeKSortedLists(vector<Node*> &lists)
{
    if (lists.empty())
    {
        cout<<"No List is present to be sorted:\n";
        return;
    }
    head=MergeKListsHelper(lists, 0, lists.size()-1);
}

List::Node*List::MergeKListsHelper(vector<Node*> &lists, int start, int end)
{
    if (start==end)
    {
        cout<<"Only one list is present which is already sorted:\n";
        //PrintList();
        return lists[start];
    }
    if (start==end+1)
    {
        return MergeSortedLists(lists[start], lists[end]);
        
    }
    int mid=start + (end-start)/2;
    Node* left= MergeKListsHelper(lists, start, mid);
    Node* right= MergeKListsHelper(lists, mid+1, end);
    return MergeSortedLists(left, right);
}

int main() {
    List list1, list2, list3;
    vector<List::Node*> lists;

    list1.AddNodeintheList(2);
    list1.AddNodeintheList(4);
    list1.AddNodeintheList(6);

    list2.AddNodeintheList(1);
    list2.AddNodeintheList(3);
    list2.AddNodeintheList(5);

    list3.AddNodeintheList(7);
    list3.AddNodeintheList(8);
    list3.AddNodeintheList(9);
    List::Node* l1=list1.head;
    List::Node* l2=list2.head;
    List::Node* l3=list3.head;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    List list4;
    list4.MergeKSortedLists(lists);    
    cout << "Merged List is: ";
    list4.PrintList();
    return 0;
}
