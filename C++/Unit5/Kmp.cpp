#include <iostream>
#include "./exercise7_7.cpp"
using namespace std;


bool pk(char* model, char* temp)
{   
    char* temp1 = model;
    char* temp2 = model+strlen(model)-strlen(temp);

    for(char* tem=temp1; tem<=temp2; tem++)
    {
        if(Pk2(tem, temp2)==1)
        {
            cout<<"找到了子串"<<endl;
            return true;
        }
    }

    cout<<"can find"<<endl;
}


// int pk2(char* a, char* b)
// {
//     int len = strlen(b);
//     for(int i=0; i<len; i++)
//     {
//         if(a[i]!=b[i])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

int main()
{
    char model[20]="hawhaha";
    char temp[20]="yyy";

    pk(model, temp);

    return 0;
}