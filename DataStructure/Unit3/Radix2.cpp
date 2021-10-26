#include <iostream>
using namespace std;


struct SqList
{
    struct StuInfo* arr;
    int length;
    int listsize;
};

struct StuInfo
{
    int keys[3];
    char no[10];
    char name[20];
    int grade;
};


void Init(SqList& a)
{
    a.arr = NULL;
    a.length = 0;
}

void InsertSql(SqList& a, StuInfo temp)
{
    
}

void Input(SqList& a)
{
    cout<<"请输入学生的个数:"<<endl;
    cin>>a.length;
    a.arr = new StuInfo[a.length];
    for(int i=0; i<a.length; i++)
    {
        cout<<"学号:"; cin>>a.arr[i].no;
        cout<<"姓名:"; cin>>a.arr[i].name;
        cout<<"成绩:"; cin>>a.arr[i].grade;
        a.arr[i].keys[0] = a.arr[i].grade/100;
        a.arr[i].keys[1] = (a.arr[i].grade/10)%10;
        a.arr[i].keys[2] = a.arr[i].grade % 10;
        cout<<"----------------"<<endl;
    }
}

void Show(SqList& a)
{
    for(int i=0; i<a.length; i++)
    {
        cout<<i+1<<" ";
        cout<<"姓名:"<<a.arr[i].name<<" "; 
        cout<<"学号:"<<a.arr[i].no<<" ";
        cout<<"成绩:"<<a.arr[i].grade<<" "; 
        cout<<endl;
    }
}

void DestroySql(SqList& a)
{
    delete [] a.arr;
    cout<<"数组已经清空了"<<endl;
}


int bitsum = 3;
// 对数组a中记录关键字的“第i位”计数， 并'按'计数数组count的值将数组a中记录复制到数组b中
// n是记录的个数， 如20个学生，n=20
void RadixPass(StuInfo a[], StuInfo b[], int n, int i)
{
    int count[10]={0};

    // for(int i=0; i<n; i++)
    // {
    //     printf("%d ", a[i].grade);
    // }

    // printf("\n");
    // eg: 12 34 54
    // i = 1;
    // count[4] = 2; (34,54)
    for(int h=0; h<n; h++)
    {
        count[a[h].keys[i]]++;
    }

    for(int j=1; j<10; j++)
    {
        count[j] = count[j] + count[j-1];
    }


    for(int k=n-1; k>=0; --k)
    {
        int j = a[k].keys[i];
        b[count[j] - 1] = a[k];
        count[j]--;
    }

    // printf("\n");

    // for(int i=0; i<n; i++)
    // {
    //     printf("%d ", b[i].grade);
    // }


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

    for(int i=0; i<num/2; i++)
    {
        int temp = a[i].grade;
        a[i].grade = a[num-i-1].grade;
        a[num-i-1].grade = temp;
    }
}


int main()
{
    SqList a;

    Init(a);
    Input(a);
    // Show(a);

    RadixSort(a.arr, a.length);

    Show(a);

    DestroySql(a);
}