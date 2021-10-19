#include <iostream>
using namespace std;

class Building
{
    private:
        char name[20];
        int number;
        int floors;
        int rooms;
        float area;

    public:
        Building(char* name, int num, int flo, int roo, float area)
        {
            strcpy(this->name, name);
            this->number = num;
            this->floors = flo;
            this->rooms = roo;
            this->area = area;
        }

        void Show()
        {
            cout<<"楼栋信息:"<<endl;
            cout<<"建筑物名称:"<<name<<endl;
            cout<<"层数:"<<floors<<endl;
            cout<<"房间数:"<<rooms<<endl;
            cout<<"建筑面积:"<<area<<endl;
        }
};

class Dorm_Building:public Building
{
    private:
        int cup;

    public:
        Dorm_Building(char* name, int number, int floors, int rooms, float area, int cup):Building(name, number, floors, rooms, area)
        {
            this->cup = cup;
        }

    void Show()
    {
        Building::Show();
        cout<<"容纳人数:"<<cup<<endl;
    }
};


class Teach_Building:public Building
{
    private:
        char func[20];

    public:
        Teach_Building(char* name, int number, int floors, int rooms, float area, char* func):Building(name, number, floors, rooms, area)
        {
            strcpy(this->func, func);
        }

    void Show()
    {
        Building::Show();
        cout<<"用处:"<<func<<endl;
    }
};

int main()
{
    class Building build("普通建筑", 20, 7, 200, 10000);
    build.Show();

    cout<<endl;

    class Dorm_Building dorm_7("南湖7栋", 7, 7, 140, 500, 200);
    dorm_7.Show();

    cout<<endl;

    char fun[20] = {"学生学习"};
    class Teach_Building Zhonghe("南湖综合楼", 1, 11, 300, 700, fun);
    Zhonghe.Show();
}