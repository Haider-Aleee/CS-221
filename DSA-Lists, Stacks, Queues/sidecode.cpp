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
    double PopDouble();
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
            P = P + Q[i];
        }
        else if (Q[i] == '(')
        {
            stack.Push('(');
        }
        else if (Q[i] == '+' || Q[i] == '-' || Q[i] == '*' || Q[i] == '/')
        {
            temp = stack.TOP();
            while (Precedence(temp) >= Precedence(Q[i]) && temp != '(')
            {
                P = P + stack.Pop();
                temp = stack.TOP();
            }
            stack.Push(Q[i]);
        }
        else if (Q[i] == ')')
        {
            while (stack.TOP() != '(')
            {
                temp = stack.Pop();
                P = P + temp;
            }
            // Pop '('
            var = stack.Pop();
        }
    }
    // Pop any remaining operators from the stack
    while (!stack.isEmpty())
    {
        P = P + stack.Pop();
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
    // Convert the double to a string using std::to_string
    std::string strValue = std::to_string(value);

    // Push the entire string onto the stack
    for (char c : strValue) {
        Push(c);
    }
}




double STACK::PostfixEvaluation(string& P)
{
    STACK stack2;
    double result;
    double operand;
    for (int i = 0; i < P.length(); i++)
    {
        if (isdigit(P[i]))
        {
            // Read the entire operand as a string
            std::string operandStr;
            while (isdigit(P[i]) || P[i] == '.') {
                operandStr += P[i];
                i++;
            }

            // Convert the string to a double and push onto the stack
            stack2.PushDouble(std::stod(operandStr));
            // Adjust i to the correct position
            i--;
        }
        else if (P[i] == '+' || P[i] == '-' || P[i] == '*' || P[i] == '/')
        {
            operand = stack2.PopDouble();
            switch (P[i])
            {
            case '+':
                stack2.PushDouble(stack2.PopDouble() + operand);
                break;
             case '-':
                stack2.PushDouble(stack2.PopDouble() - operand);
                break;
             case '*':
                stack2.PushDouble(stack2.PopDouble() * operand);
                break;
             case '/':
                stack2.PushDouble(stack2.PopDouble() / operand);
                break;
             case '^':
                stack2.PushDouble(pow(stack2.PopDouble(), operand));
                break;
            default:
                break;
            }
        }
    }
    return stack2.PopDouble();
}

double STACK::PopDouble() {
    std::string strValue;
    while (top != nullptr && isdigit(top->data)) {
        strValue = top->data + strValue;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    return std::stod(strValue);
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