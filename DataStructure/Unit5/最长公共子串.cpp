#include <iostream>
using namespace std;

// 
void Substring(char *&sub, char* str, int s, int len)
{

}

// 求最长公共子串的算法
void MaxSameSubstring(char* string1, char* string2, char *&sub)
{
    // 返回string1和string2的最长公共子串sub的长度
    // 竖着的是string1, 横着的是string2;
    char* p1;
    char* p2;
    p1 = string1;
    p2 = string2;

    int m = strlen(p1);
    int n = strlen(p2);

    int mat[n][m];

    for(int i=0; i<m; i++)  // 行
    {
        for(int j=0; j<n; j++)
        {
            if(p1[i] == p2[j])
                mat[i][j]=1;
            else    
                mat[i][j]=0;
        }   
    }
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    char string1[]={"zhang"};
    char string2[]={"kuang"};
    char h;
    char* haha=&h;
    MaxSameSubstring(string1, string2, haha);
}