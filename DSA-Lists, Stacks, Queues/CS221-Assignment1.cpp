#include <iostream>
#include <cctype>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

class STACK
{
    struct Node
    {
        char data;
        Node* next;
        Node* prev;
    };
    Node* top= NULL;

    public:
    void Push(char value);
    char Pop();
    bool isEmpty();
    void PrintStack();
    string InfixtoPostfix(string&);
    double PostfixEvaluation(string &);
    static int Precedence(char opr);
    char TOP();
    void PushDouble(double value);
};

void STACK::Push(char value)
{
   Node* newNode= new Node;
   newNode->data= value;
   if (top==NULL)
   {
    top=newNode;
    newNode->next=top;
    newNode->prev=top;
   }
   else
   {
    newNode->next=top;
    newNode->prev=top->prev;
    top->prev->next=newNode;
    top->prev=newNode;
    top=newNode;
   }
   
}

char STACK::Pop()
{
    char num=NULL;
    if (top==NULL)
    {
        cout<<"Stack is empty\n";
        return 0;
    }

    if (top->next==top)
    {
        num=top->data;
        delete top;
        top=NULL;
        return num;
    }
    else
    {
        Node*temp= top;
        num=top->data;
        top->prev->next=top->next;
        top->next->prev=top->prev;
        top=top->next;
        delete temp;
        return num;
    }
}
char STACK::TOP()
{
    if (top!=NULL)
    {
        return top->data;
    }
    
}
bool STACK::isEmpty()
{
    if (top==NULL)
    {
        return true;
    }
    else
    return false;
}
void STACK::PrintStack()
{
    Node* temp= top;
    do
    {
        cout<<temp->data<<"-";
        temp=temp->next;
    } while (temp!=top);
    
}

string STACK::InfixtoPostfix(string& Q)
{
    STACK stack;
    char temp;
    char var;
    stack.Push('(');
    string P;
    for (int i = 0; i < Q.length(); i++)
    {
        if (isdigit(Q[i]))
        {
            P=P+Q[i];
        }
        else if (Q[i]=='(')
        {
            stack.Push('(');
        }
        else if(Q[i]=='+' || Q[i]=='-' || Q[i]=='*' || Q[i]== '/')
        {
            temp= stack.Pop();
            if (Precedence(temp)>=Precedence(Q[i]))
            {
                P=P+temp;
                stack.Push(Q[i]);
            }
            else{
                stack.Push(temp);
                stack.Push(Q[i]);
            }
        }
        else if (Q[i]==')')
        {
            while (stack.TOP()!='(')
            {
                temp=stack.Pop();
                P=P+temp;
            }
            var=stack.Pop();
        }
    }
    return P;
}

int STACK::Precedence(char opr)
{
    if (opr=='^')
    {
        return 3;
    }
    else if (opr=='/' || opr=='*')
    {
        return 2;
    }
    else if (opr=='+' || opr=='-')
    {
        return 1;
    }
    else
    return -1;
}
void STACK::PushDouble(double value) {
    // 1. Convert the double to a string using std::stringstream
    stringstream ss;
    ss << value;
    string strValue = ss.str();

    // 2. Push each character of the string onto the stack
    for (char c : strValue) {
        Push(c);
    }
}


double STACK::PostfixEvaluation(string& P)
{
    STACK stack2;
    double result;
    double operand1;
    double operand2;
    char opr;
    for (int i = 0; i<P.length(); i++)
    {
        if (isdigit(P[i]))
        {
            stack2.Push(P[i]);
        }
        else if (P[i]=='+' || P[i]=='-' || P[i]=='*' || P[i]=='/')
        {
            operand1=stack2.Pop()-'0';
            operand2=stack2.Pop()-'0';
            switch (P[i])
            {
            case '+':
                //result=operand2+operand1;
                stack2.PushDouble(operand2+operand1);
                break;
             case '-':
                //result=operand2-operand1;
                stack2.PushDouble(operand2-operand1);
                break;
             case '*':
                //result=operand2*operand1;
                stack2.PushDouble(operand2*operand1);
                break;
             case '/':
                //result=operand2/operand1;
                stack2.PushDouble(operand2/operand1);
                break;
             case '^':
                //result=pow(operand2,operand1);
                stack2.PushDouble(pow(operand2,operand1));
                break;
            default:
                break;
            }
        }
        
    }
    return stack2.Pop()-'0';
}

int main()
{
    //string input="((3+5)*(2-4))/6^2)";
    string input="12+3*8*(3/4-2))";
    string res1;
    double res2;
    STACK inst;
    res1=inst.InfixtoPostfix(input);
    cout<<"Postfix expression is: "<<res1<<endl;
    res2= inst.PostfixEvaluation(res1);
    cout<<"Postfix evaluation is: "<<res2<<endl;
    return 0;
}