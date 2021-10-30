#include <iostream>
using namespace std;

int num;

struct StuInfo
{
    int keys[3];
    char no[10];
    char name[20];
    int grade;
};

int bitsum = 3;
// 对数组a中记录关键字的“第i位”计数， 并'按'计数数组count的值将数组a中记录复制到数组b中
// n是记录的个数， 如20个学生，n=20
void RadixPass(StuInfo a[], StuInfo b[], int n, int i)
{
    int count[10]={0};

    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i].grade);
    }

    // printf("\n");
    // eg: 12 34 54
    // i = 1;
    // count[4] = 2; (34,54)
    for(int h=0; h<n; h++)
    {
        count[a[h].keys[i]]++;
    }

    // for(int i=0; i<10; i++)
    // {
    //     printf("%d ", count[i]);
    // }

    for(int j=1; j<10; j++)
    {
        count[j] = count[j] + count[j-1];
    }

    // for(int i=0; i<10; i++)
    // {
    //     printf("%d ", count[i]);
    // }

    for(int k=n-1; k>=0; --k)
    {
        int j = a[k].keys[i];
        b[count[j] - 1] = a[k];
        count[j]--;
    }

    printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("%d ", b[i].grade);
    }

    // for(int i=0; i<n/2; i++)
    // {
    //     int temp = b[i].grade;
    //     b[i].grade = b[n-i-1].grade;
    //     b[n-i].grade = temp;
    // }

    // printf("\n");
}


// n是数据的个数
void RadixSort(StuInfo a[], int num)
{
    int i;
    StuInfo c[num];
    i = bitsum - 1;

    while(i>=0)
    {
        RadixPass(a, c, num, i);
        i--;

        if(i>=0)
        {
            RadixPass(c, a, num, i);
            i--;
        }
        else{
            for(int j=0; j<3; ++j)
                a[j] = c[j];
        }
    }
}





int main()
{
   
    int count=0;
    cout<<"请输入学生的个数:"<<endl;
    cin>>num;
    StuInfo a[num];

    cout<<"请开始输入学生信息:"<<endl;

    for(int i=0; i<num; i++)
    {
        cout<<"学号:"; cin>>a[i].no;
        cout<<"姓名:"; cin>>a[i].name;
        cout<<"成绩:"; cin>>a[i].grade;
        a[i].keys[0] = a[i].grade/100;
        a[i].keys[1] = (a[i].grade/10)%10;
        a[i].keys[2] = a[i].grade % 10;
        cout<<"----------------"<<endl;
    }

    RadixSort(a, num);

    for(int i=0; i<num/2; i++)
    {
        int temp = a[i].grade;
        a[i].grade = a[num-i-1].grade;
        a[num-i-1].grade = temp;
    }

    // printf("\n");
    // RadixPass(a, b, num, 2);

    // 输出学生信息
    cout<<endl;
    cout<<"排名情况如下:"<<endl;
    for(int i=0; i<num; i++)
    {
        cout<<i+1<<" ";
        cout<<"姓名:"<<a[i].name<<" "; 
        cout<<"学号:"<<a[i].no<<" ";
        cout<<"成绩:"<<a[i].grade<<" "; 
        cout<<endl;
    }

    // delete []a;
}