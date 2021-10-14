#include <iostream>
using namespace std;


// 一次划分
int Partition(int* arr, int low, int high)
{
    int start = low;
    int temp=arr[low];
    low=low+1;

    while(low<high)
    {
        while(low<high && arr[high]>=temp)
        {
            high--;
        }

        while(low<high && arr[low]<temp)
        {
            low++;
        }

        int a=arr[low];
        arr[low]=arr[high];
        arr[high]=a;
    }

    arr[start] = arr[low];
    arr[low] = temp;

    return low;
}

int Partition2(int* arr, int low, int high)
{
    int temp=arr[low];

    while(low<high)
    {
        while(low<high && arr[high]>=temp)
        {
            high--;
        }

        if(low<high)
        {
            arr[low++]=arr[high];
        }

        while(low<high && arr[low]<=temp)
        {
            low++;
        }

        if(low<high)
        {
            arr[high--]=arr[low];
        }
    }

    arr[low]=temp;

    return low;
}