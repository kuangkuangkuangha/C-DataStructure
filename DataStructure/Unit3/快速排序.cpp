// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>

int Partition(int R[], int low, int high)
{
    int tag = R[low];
    int* start = &R[low], *end = &R[high];
    int n;

    while (start < end)
    {
        while (start < end)
        {
            if (*end < tag)
            {
                *start = *end;
                start++;
                break;
            }

            end--;
        }


        while (start < end)
        {
            if (*start > tag)
            {
                *end = *start;
                end--;
                break;
            }

            start++;
        }
    }
    *start = tag;

    n = start - R;

    return n;
}

void QSort(int R[], int s, int t)
{

    int pivotloc;
    if (s < t)
    {
        pivotloc = Partition(R, s, t);
        QSort(R, s, pivotloc - 1);
        QSort(R, pivotloc + 1, t);
    }

}

int main()
{
    int R[10] = { 1,10,9,8,5,2,3,4,7,6 };

    QSort(R, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d ", R[i]);
    printf("\n");
    return 0;
}
