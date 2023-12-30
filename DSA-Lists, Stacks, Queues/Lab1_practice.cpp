// Dynamic 2D MEMORY ALLOCATION:

//Method 1:

/*#include <iostream>
using namespace std;
int main()
{
    int m=3, n=4, c=0;
    
    int *arr= new int[m*n];   /*new return address of array of size 12 which is stored in
                                dynamic array arr*/

    /*for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(arr+ i*n+j) = ++c;  /* for first iteration:
                                    i=0 then i*n = 0*4 = 0 then i*n+j = 0+0 = 0 and 
                                    then adress of this 0 is added to arr which determines 
                                    the first box in array and then dereferenced by * to get value 
                                    of this resultant address */
        /*}
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< *(arr+ i*n+j) <<" ";
        }
        cout<<endl;
    }

    delete[] arr;
    return 0;
}*/

// Method 2:

#include <iostream>
using namespace std;
int main()
{
    int m=3, n=4, c=0;
    
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = ++c;
        }
    }
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }

     for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
