#include <iostream>
#include "StackConfig.cpp"
using namespace std;


// 已知n件物品的体积分别为w[0],w[1]...w[n-1], 背包的总体积为T
void knapsack(int w[], int T, int n)
{
    Stack a;
    InitStack(&a);
    int k=0;

    do
    {
        while(T>0 && k<n)
        {
            if(T-w[k] >= 0)
            {
                Push(&a, k); 
                T -= w[k];
            }
            k++;
        }

        if(T == 0)
        {
            cout<<"找到一组解(物品的序号):";
            Traverse(&a);
            cout<<endl;
        }

        Pop(&a, &k);
        T += w[k];
        k ++;

    }while(!StackEmpty(&a) || k<n);
}


int main()
{   
    int num;
    cout<<"请输入物品的个数:"<<endl;
    cin>>num;
    int w[num];

    cout<<"请开始输入物品质量:"<<endl;
    for(int i=0; i<num; i++)
    {
        cout<<"请输入第"<<i+1<<"个物品的体积:";
        cin>>w[i];
    }
    
    int T;
    cout<<"请输入背包的容量:"<<endl;
    cin>>T;

    knapsack(w, T, num);

}