//---Min Stack---

#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    public:

    struct Node
    {
        double data;
        Node* next;
    };
    Node* top=NULL;

    void Push(double newVal);
    void Pop();
    bool isEmpty();
    double Top();
    double getMin();
};

void Stack::Push(double newVal)
{
    Node* newNode= new Node;
    newNode->data=newVal;
    if (top==NULL)
    {
        newNode->next=NULL;
        top=newNode;
        return;
    }
    newNode->next=top;
    top=newNode;
}
void Stack::Pop()
{
    if (isEmpty())
    {
        cout<<"Stack underflow!!!\n";
        return;
    }
    Node* temp= top;
    double val= temp->data;
    top=top->next;
    delete temp;
    //return val;
}
bool Stack::isEmpty()
{
    if (top==NULL)
    {
        return true;
    }
    else
    return false;
}

double Stack::Top()
{
    double retVal;
    retVal=top->data;
    return retVal;
}

double Stack::getMin()
{
    Node* temp=top;
    double minVal=temp->data;
    while (temp->next!=NULL)  
    {
        if (minVal>temp->next->data)
        {
            minVal=temp->next->data;
        }
        temp=temp->next;
    }
    return minVal;
}

int main()
{
    Stack myStack;
    double min;
    myStack.Push(-2);
    myStack.Push(0);
    myStack.Push(-3);
    min=myStack.getMin();
    cout<<min<<endl;
    myStack.Pop();
    double t=myStack.Top();
    cout<<t<<endl;
    double m=myStack.getMin();
    cout<<m<<endl;
    return 0;
}