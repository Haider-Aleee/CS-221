#include <iostream>
using namespace std;
int main()
{
    int SIZE;
    cout<<"Enter the size of array:\n";
    cin>>SIZE;
    int* ptr= new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        int num;
        cout<<"Enter Number "<<i+1<<endl;
        cin>>num;
        ptr[i] = num;
    }
    for (int i = SIZE-1; i>=0; i--)
    {
        cout<<ptr[i]<<" ";
    }
    delete[] ptr;
    return 0;
}