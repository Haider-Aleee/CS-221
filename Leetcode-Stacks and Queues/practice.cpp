/*#include <iostream>
using namespace std;
class Queue
{
    public:
    struct Node
    {
        int data;
        Node*prev;
        Node*next;
    };
    Node*front=NULL;
    Node*rear=NULL;

    void Enqueue(int val);
    void dequeue();
    void PrintQueue();
};
void Queue::Enqueue(int val)
{
    Node*newNode= new Node;
    newNode->data=val;
    if (front==NULL && rear==NULL)
    {
        newNode->next=NULL;
        newNode->prev=NULL;
        front=newNode;
        rear=newNode;
        return;
    }
    rear->next=newNode;
    newNode->next=front;
    newNode->prev=rear;
    front->prev=newNode;
    rear=rear->next;
}
void Queue::dequeue()
{
    Node*temp=front;
    front=front->next;
    temp->next=NULL;
    temp->prev=NULL;
    front->prev=rear;
    rear->next=front;
    delete temp;
}
void Queue::PrintQueue()
{
    Node*temp=front;
    while (temp!=rear)
    {
        cout<<temp->data<<"-";
        temp=temp->next;
    }
}

int main()
{
    Queue myQueue;
    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);
    myQueue.Enqueue(4);
    myQueue.Enqueue(5);
    myQueue.Enqueue(6);
    myQueue.Enqueue(7);
    cout<<"Initial Queue is: "<<endl;
    myQueue.PrintQueue();
    cout<<endl;
    myQueue.dequeue();
    myQueue.dequeue();
    cout<<"After deletion :\n";
    myQueue.PrintQueue();
    return 0;
}*/


#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    public:
    struct Node
    {
        int data;
        Node* next;
    };
    Node*top=NULL;

    void push(int val);
    void pop();
    int Top();
    bool isEmpty();
    vector<int> nge(vector<int>&num1, vector<int>&num2);
};
void Stack::push(int val)
{
    Node* newNode=new Node;
    newNode->data=val;
    if (top==NULL)
    {
        newNode->next=NULL;
        top=newNode;
        return;
    }
    newNode->next=top;
    top=newNode;
}
void Stack::pop()
{
    Node*temp=top;
    top=top->next;
    temp->next=NULL;
    delete temp;
}
int Stack::Top()
{
    int num=top->data;
    return num;
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
vector<int> Stack::nge(vector<int>&num1, vector<int>&num2)
{
    vector<int>ans;
    Stack st;
    for (int i = num1.size()-1; i>=0; i--)
    {
        for (int j = num2.size()-1; j >=0; j--)
        {
            if (num1[i]==num2[j])
            {
                st.push(j);
            }
        }
    }
    while (!st.isEmpty())
    {
        bool flag=false;
        for (int j = st.Top(); j <num2.size(); j++)
        {
            if (num2[st.Top()]<num2[j])
            {
                ans.push_back(num2[j]);
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            ans.push_back(-1);
        }
        st.pop();
    }
    return ans;
}
int main()
{
    vector<int>v1={4,1,2};
    vector<int>v2={1,3,4,2};
    Stack myStack;
    vector<int>answer;
    answer=myStack.nge(v1,v2);
    cout<<"[";
    for (int i = 0; i < answer.size(); i++)
    {
        cout<<answer[i]<<",";
    }
    cout<<"]";
    return 0;
}