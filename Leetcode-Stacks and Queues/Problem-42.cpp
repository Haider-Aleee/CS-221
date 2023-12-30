//Trapping Rain Water

/*class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int lpos = 1;
        int rpos = n-2;
        int water = 0;
        while(lpos <= rpos)
        {
            if(height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if(height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if(lmax <= rmax && height[lpos] < lmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        
        }
        return water;
    }
};*/




// -------------------------OOOOOOOOOOOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRRRRRRRRRRRRR-----------------------

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
    Node* top=NULL;

    void Push(int newVal);
    int Pop();
    bool isEmpty();
    int Top();
    int MinofHeights(int, int);
    int trapRainwater(vector<int>&height);
};

void Stack::Push(int newVal)
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
int Stack::Pop()
{
    if (isEmpty())
    {
        cout<<"Stack underflow!!!\n";
        return -1;
    }
    Node* temp= top;
    int val= temp->data;
    top=top->next;
    delete temp;
    return val;
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

int Stack::Top()
{
    int retVal;
    retVal=top->data;
    return retVal;
}

int Stack::MinofHeights(int num1, int num2)
{
    if (num1<num2)
    {
        return num1;
    }
    else
    return num2;
    
}
int Stack::trapRainwater(vector<int>&height)
{
    Stack leftstack;
    Stack rightStack;
    int water=0;
    //Stack ResStack;
    int lmax= height[0];
    int sizeofVector=height.size();
    int rmax=height[sizeofVector-1];
    for (int i = 0; i < sizeofVector; i++)
    {
        if (lmax<=height[i])
        {
            lmax=height[i];
        }
        leftstack.Push(height[i]);
        if (height[i]>=rmax)
        {
            rmax=height[i];
        }
        rightStack.Push(height[i]);
    }
    for (int i = 0; i < sizeofVector; i++)
{
    int minHeight = MinofHeights(leftstack.Top(), rightStack.Top());
    if (minHeight > height[i])
    {
        water += minHeight - height[i];
    }
    leftstack.Pop();
    rightStack.Pop();
}
    while (!isEmpty())
    {
        water += Pop();
    }
    return water;
}

int main()
{
    Stack myStack;
    int result;
    vector<int> heights;
    heights.push_back(4);
    heights.push_back(2);
    heights.push_back(0);
    heights.push_back(3);
    heights.push_back(2);
    heights.push_back(5);
    /*heights.push_back(0);
    heights.push_back(1);
    heights.push_back(0);
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(0);
    heights.push_back(1);
    heights.push_back(3);
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(2);
    heights.push_back(1);*/
    result=myStack.trapRainwater(heights);
    cout<<"Units of water stored is: "<<result<<endl;
    return 0;
}