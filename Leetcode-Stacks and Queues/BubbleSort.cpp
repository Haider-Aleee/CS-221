#include <iostream>
using namespace std;

void BubbleSort(int array[], int size)
{
    for (int step = 0; step < size; step++)
    {
        for (int i = 0; i < size-step; i++)
        {
            if (array[i]>array[i+1])
            {
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
}

void InsertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key=array[step];
        int j=step-1;
        while (key<array[j] && j>=0)
        {
            array[j+1]=array[j];
            --j;
        }
        array[j+1]=key;
    }
    
}
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

void SelectionSort(int array[], int size)
{
    for (int step = 0; step < size-1; step++)
    {
        int min_idx=step;
        for (int i = step+1; i < size; i++)
        {
            if (array[i]<array[min_idx])
            {
                min_idx=i;
            }
        }
        swap(&array[min_idx], &array[step]);
    }
}

void PrintArray(int array[],int size)
{
    for (int i = 0; i <size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int data[]={-2,5,7,0,8,1,5};
    int size=sizeof(data)/sizeof(data[0]);
    cout<<"Before Sorting: ";
    PrintArray(data,size);
    //BubbleSort(data,size);
    //InsertionSort(data,size);
    SelectionSort(data,size);
    cout<<"After Sorting: ";
    PrintArray(data,size);
    return 0;
}