#include <iostream>
#include "config.cpp"
using namespace std;

// 选择排序
void SelectSort(int* arr, int len)
{
    for(int i=0; i<len-1; i++)
    {
        int min = i;
        for(int j=i+1; j<len; j++)
        {
            if(arr[min]>arr[j])
            {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// 插入排序
void InsertSort(int* arr, int len)
{
    int temp;
    for(int i=2; i<=len; i++)
    {
        arr[0] = arr[i];
        for(temp=i-1; arr[temp]>arr[0]; temp--)
        {
            arr[temp+1] = arr[temp];
        }

        arr[temp+1] = arr[0];
    }
}

// 冒泡排序
// a[5]={0,3,1,5,2} 排序的数只有四个因为a[0]要当哨兵
void BubbleSort(int* arr, int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// 快速排序 r和s就是数组下标
void QSort(int* arr, int s, int t)
{   
    if(s<t)
    {
        int mid = Partition2(arr, s, t);
        QSort(arr, s, mid-1);
        QSort(arr, mid+1, t);
    }
}   


// 归并排序
void MergeSort(int* arr)
{

}


// 基数排序
// 对数组a中的关键字的‘第i位’计数， 并按计数数组count的值
// 将数组a中记录复制到数组b中去
void RadixSort(int* a, int* b, int n, int i)
{

}


 void RadixPass(int* a, int len)
{
    int count[10];
    int b[len];

    for(int i=0; i<10; i++)         // 将count数组清零
        count[i]=0;

    for(int i=0; i<len; i++)
    {                               // 对数组进行计数
        count[a[i]]++;
    }


    for(int i=1; i<10; ++i)
    {                                       // 对计数数组求和
        count[i]=count[i]+count[i-1];
    }


    for(int k=len-1; k>=0; k--)                 // 这里要=, 不知道为啥
    {
        b[count[a[k]]-1] = a[k];             // 对数组进行排序
        count[a[k]]--;
    }


    for(int i=0; i<len; i++)
        cout<<b[i]<<endl;
}

// 将数组元素全部输出
void Traverse(int* arr, int len)
{
    cout<<"数组元素是:"<<endl;
    for(int i=0; i<len; i++)
    {
        cout<<arr[i]<<endl;
    }
}


int main()
{
    int a[8]={6,5,4,0,1,2,7,9};
    // BubbleSort(a,7);
    // SelectSort(a,8);
    // InsertSort(a, 6);
    // a[0]=0;
    // RadixPass(a, 8 );
    QSort(a, 0, 7);
    // partition(a, 0, 5);
    Traverse(a, 8);
}