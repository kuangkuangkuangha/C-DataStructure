#include <iostream>
using namespace std;


void Diagscan(int **mat, int i, int j, int row, int col, int &maxlen,int &jpos)//扫描对角线的函数
{
	int len = 0;
	if (i == row - 1 || j == col - 1)
	{
		if (mat[i][j] == 1)
		{
			len = 1;
			if (maxlen < len)
			{
				maxlen = len;
				jpos = j;
			}
		}

		return;
	}

	while (i < row && j < col)
	{
		if (mat[i][j] == 1)
			len++;
		else
			len = 0;

		if (maxlen < len)
		{
			maxlen = len;
			jpos = j;
		}

		i++;
		j++;
	}
	
}


// 从字符串str（起始地址）中，返回 元素位置（1，2，3，4）为s， 长度为 len的子串
// 子串用sub接收
void SubString(char** sub, char* str, int s, int len)//求最长子串, s为下标
{
	char* p;
	int k;

    *sub = new char [len+1];
	p = str + s;
	k = 0;
	while (k < len)
	{
		(*sub)[k] = *p;
		p++;
		k++;
	}
	(*sub)[k] = '\0';
}


// 扫描所有的所有的对角线中出现的最长的长度为1的子串
void Diagmaxl(int** mat, int& maxlen, int& jpos, int row, int col)//求最大公共长度及下标
{
	int istart = 0;
	int jstart = col - 1;
	int i, j;

	for (int k = istart - jstart; k < row; k++)
	{
		if (k <= 0)
		{
			i = 0;
			j = -k;
		}

		else
		{
			j = 0;
			i = k;
		}

		Diagscan(mat, i, j, row, col, maxlen, jpos);
	}

	jpos = jpos - maxlen + 1;
}


// 求最长公共子串的算法
// 在string1和string2中找到最长公共子串，用sub接收返回
int Maxsamesubstring(char* string1, char* string2, char*& sub)
{
	int row = strlen(string2);
	int col = strlen(string1);
	

// 动态生成数组
	int** mat = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
		mat[i] = (int*)malloc(sizeof(int) * col);


// 构造mat的0-1数组
	for(int i=0; i<row; i++)
		for (int j = 0; j < col; j++)
		{
			if (string2[i] == string1[j])
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}  


	int maxlen = 0, jpos = -1;

// 得到子串的在string1的 起始位置jpos 和 长度maxlen
	Diagmaxl(mat, maxlen, jpos, row, col);

// 根据得到的 jpos 和 maxlen 直接Substring
	if (maxlen == 0) 
		*sub = '\0';
	else 
		SubString(&sub, string1, jpos, maxlen);


// 输出结果
    cout<<"最大公共子串:"<<sub<<endl;
    cout<<"长度为:"<<maxlen<<endl;
	return maxlen;
}

 
int main()
{
	char string1[20] ;
	char string2[20] ;
	char* sub;

    cout<<"请输入主串:"<<endl;
    cin>>string1;

    cout<<"请输入匹配串:"<<endl;
    cin>>string2;
	Maxsamesubstring(string1, string2, sub);

	return 0;
}