#include <iostream>
using namespace std;
#define SIZE 10;

class Stack
{
    private:
        char* arr;
        int top;

    public:
        Stack()
        {
            arr = new char[10];
            top = -1;
        };

        // 出栈
        char Pop()
        {
            return arr[top--];
        };

        // 压栈
        void Push(char a)
        {
            top++;
            arr[top] = a;
        }

        void Min()
        {
            char min;
            char temp;
            min = Pop();

            while(top>=0)
            {
                temp = Pop();
                if(temp < min)
                {
                    min = temp;
                }
            }

            cout<<"最小的字符是:"<<min<<endl;
        }

        ~Stack()
        {
            delete [] arr;
            cout<<"数据已经被清空了"<<endl;
        }
};

int main()
{
    Stack a;
    // 入栈
    a.Push('j');
    a.Push('b');
    a.Push('g');
    a.Push('w');
    a.Push('f');
    a.Push('l');

    a.Min();  
}