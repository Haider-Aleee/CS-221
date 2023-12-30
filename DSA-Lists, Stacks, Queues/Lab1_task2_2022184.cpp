#include <iostream>
using namespace std;
int main()
{
    int *array[5];
    int total=0;
    for (int i = 0; i <5; i++)
    {
        int num;
        cout<<"Enter number "<<i+1<<endl;
        cin>>num;
        array[i]= new int(num);
        total= total+ (*array[i]);
    }
    cout<<"Sum of all numbers is: "<<total<<endl;
    for (int i = 0; i <5; i++)
    {
        delete array[i];
    }
    return 0;
}