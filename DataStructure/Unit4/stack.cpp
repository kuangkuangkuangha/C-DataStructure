#include <iostream>
#include "config.cpp"
using namespace std;


int main()
{   
    Stack a;
    InitStack(&a);
    Push(&a,8);

    int e;
    Pop(&a, &e);
    cout<<"pop:"<<e;
}