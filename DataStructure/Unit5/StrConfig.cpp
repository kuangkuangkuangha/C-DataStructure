#include <iostream>
using namespace std;

// chars是字符串常量，把chars赋为T的值
void StrAssign(char&T, string chars)
{

}

// 串S存在
// 由串S复制得串T
void StrCopy(char* &T, const string S)
{
    int i=0;
    int lens = StrLength(S);
    T = new char[lens+1];
    while(S[i]!='\0')
    {
        T[i] = S[i];
        i++;
    }
}

// 串S存在
// 若S为空串，则返回TRUE，否则返回FALSE
void StrEmpty(char& S)
{

}

// 串S和T存在
// 若S<T, 则返回值<0；若S=T，则返回值=0；若S>T，则返回值>0
int StrCompare(const string S, const string T)
{
    int i=0;
    while(S[i]!='\0' && T[i]!='\0')
    {
        if(S[i]<T[i])
            return -1;
        else if(S[i]>T[i])
            return 1;
        else
            i++; 
    }

    if(S[i]=='\0' && T[i]=='\0')
        return 0;
    else if(S[i]=='\0' && T[i]!='\0')
        return -1;
    else
        return 1;
}

// 串S存在
// 返回S的元素个数，称为串的长度
int StrLength(const string S)
{
    int lenth=0;
    for(int i=0; S[i]!='\0'; i++)
    {
        lenth++;
    }
    return lenth;
}

// 串S1和S2存在
// 用T返回由S1和S2连接而成的新串
void Concat(char* & T, string S1, string S2)
{
    int len1 = StrLength(S1);
    int len2 = StrLength(S2);
    int lenT = len1 + len2;

    T = new char[lenT+1];
    int temp=0;

    for(int k=0; k<len1; k++)
    {
        T[temp++] = S1[k];
    }

    for(int i=0; i<len2; i++)
    {
        T[temp++] = S2[i];
    }
}

// 串S存在，0 <=pos< StrLength(S) 且 0 <=len<= StrLength(S)-pos
// 用sub返回串S的第pos个字符起长度为len的子串
// pos 是下标 不是位置
void SubString(char* &sub, const string S, int pos, int len)
{
    sub = new char[len+1];
    for(int i=pos; i<=pos+len; i++)
    {
        // cout<<i<<S[i]<<endl;
        *sub = S[i];
        sub++;
    }

    *sub = '\0';
    sub = sub-len-1;    // 指针复位
}

// 串S和T存在，T是非空串，0<= pos <= StrLength(S)-1
// 若主串S中存在和串T值相同的子串，则返回它在主串S中第
// pos个字符之后第一个出现的位置；否则函数值为-1
void Index(string S, string T, int pos)
{

}

// 串S，T和V存在，T是非空串
// 用V替换主串S中出现的所有与T相等的不重叠的子串
void Replace(char& S, string T, string V)
{

}

// 串S和T存在，0<= pos <=StrLength(S)
// 在串S的第pos个字符之前插入串T
void StrInsert(char& S, int pos,  string T)
{

}

// 串S存在，0<= pos <=StrLength(S) - len
// 从串S中删除第pos个字符起长度为len的子串
void StrDelete(char& S, int pos, int len)
{

}

// 串S存在，串S被销毁
void DestroyString(char& S)
{

}


int main()
{
    // char* s;
    // string b="zhangkuang";
    // cout<<"legth"<<StrLength(b)<<endl;
    // SubString(s, b, 5,5);
    // cout<<s<<endl;

    string a="abcbili";
    string b="defg";
    char* an;
    Concat(an,a,b);
    cout<<an<<endl;
    char* bn;
    StrCopy(bn, an);
    cout<<bn<<endl;
}
