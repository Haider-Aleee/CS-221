#include <iostream>
using namespace std;

class List
{
    struct Node
    {
        int data;
        Node*next;
    };
    Node* head=NULL;
    public:
    void AddNode(string &value);
    List* sumList(List*, List*);
    void PrintList();
};
void List::AddNode(string &value)
{
    int *array=new int[value.length()];
    for(int i=0; i<value.length(); i++)
    {
        array[i]=value[value.length()-i-1]-'0';
    }
    for(int i=0; i<value.length(); i++)
    {
        Node* newNode= new Node;
        newNode->data=array[i];
        newNode->next=NULL;
        if(head==NULL)
        {
            newNode->next=head;
            head=newNode;
        }
        else
        {
            Node* temp=head;
            temp->next=newNode;
            delete temp;
        }
    }
}

List* List::sumList(List* l1, List* l2)
{
    List* l3;
    string result;
    double sum=0;
    int carry=0;
    int temp;
    while(l1->head!=NULL || l2->head!=NULL||carry!=0)
    {
        int sum = (l1->head ? l1->head->data : 0) + (l2->head ? l2->head->data : 0);
        carry=sum/10;
        temp=sum%10;
        result="temp";
        List::Node* newNode = new List::Node;
        newNode->data = sum % 10;
        newNode->next = l3->head;
        l3->head = newNode;
       if (l1->head)
            l1->head = l1->head->next;
        if (l2->head)
            l2->head = l2->head->next;
    }
    return l3;
}
void List::PrintList()
{
    Node*temp=head;
    if(temp==NULL)
    {
        cout<<"List is empty:\n";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<",";
        temp=temp->next;
    }
}

int main()
{
    List list1, list2, list3;
    string num1;
    string num2;
    cout<<"Enter any two numbers:\n";
    cin>>num1;
    cin>>num2;
    list1.AddNode(num1);
    cout<<"List 1 is: ";
    list1.PrintList();
    list2.AddNode(num2);
    cout<<"List 2 is: ";
    list2.PrintList();
    list3.sumList(&list1,&list2);
    cout<<"SUm List is: ";
    list3.PrintList();
    return 0;
}