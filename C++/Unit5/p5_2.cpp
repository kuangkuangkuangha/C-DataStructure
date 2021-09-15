#include <iostream>
using namespace std;

// 基本的字符串类
class String
{
    private:
        char *Str;
        int len;

    public:
        void stringInfo()
        {
            cout<<"string:"<<Str<<";  "<<"lenth:"<<len<<endl;
        }

        // 两个构造函数
        String(const char* str)
        {
            len=strlen(str);
            Str = new char[len+1];
            strcpy(Str, str);
        }

        String()
        {
            len=0;
            Str=NULL;
        }

        // 一个析构函数
        ~ String()
        {
            delete []Str;
            cout<<"字符串对象已经清理完毕"<<endl;
        }
};


int main()
{
    char s[]={"cyw"};

    class String c1("haha");
    c1.stringInfo();

    class String c2(s);
    c2.stringInfo();

}