//Valid Parenthesis

#include <iostream>
#include <string>
using namespace std;
class Stack
{
    public:

    struct Node
    {
        char data;
        Node* next;
    };
    Node* top=NULL;

    void Push(char newVal);
    void Pop();
    bool isEmpty();
    char Top();
    bool isValid(string s);
};

void Stack::Push(char newVal)
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
    char val= temp->data;
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

char Stack::Top()
{
    char retVal;
    retVal=top->data;
    return retVal;
}

bool Stack::isValid(string s)
{
    int n= s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            Push(s[i]);
        }
        else
        {
            char c= Top();
            if (isEmpty() || (s[i]==')' && c!='(') || (s[i]=='}' && c!='{') || (s[i]==']' && c!='['))
            {
                return false;
            }
            Pop();
        }
    }
    return isEmpty();
}

int main()
{
    Stack myStack;
    string str;
    cout<<"Enter a string of parenthesis:\n";
    cin>>str;
    if(myStack.isValid(str))
    {
        cout<<"Valid Parenthesis::\n";
    }
    else 
    cout<<"Invalid Parenthesis::\n";

    return 0;
}