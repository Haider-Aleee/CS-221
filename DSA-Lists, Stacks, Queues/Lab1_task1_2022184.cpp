#include <iostream>
using namespace std;

void SwapTwoNumbers (int* num1, int* num2);

int main()
{
    int a, b;
    int* aPtr= &a;
    int* bPtr= &b;

    cout<<"Enter any two numbers:\n";
    cin>>a;
    cout<<"Enter second:\n";
    cin>>b;
    SwapTwoNumbers(aPtr, bPtr);
    return 0;
}

void SwapTwoNumbers (int* num1, int* num2)
{
    cout<<"First number is: "<<*num1<<endl;
    cout<<"Second number is: "<<*num2<<endl;
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    cout<<"After swapping:\n";
    cout<<"First number is: "<<*num1<<endl;
    cout<<"Second number is: "<<*num2<<endl;
}