#include <iostream>
using namespace std;

class Table
{
    private:
        int high;

    public:
        Table(float h)
        {
            this->high = h;
        }

        float Show()
        {
            return high;
        }
};

class Round
{   
    private:
        float radius;
    
    public:
        Round(int r)
        {
            this->radius = r;
        }

        float Area()
        {
            return 3.14*radius*radius;
        }
};

class RoundTable: public Round, public Table
{
    private:
        char color[20];
    public:

        RoundTable(char* color, float height, float radius):Round(radius), Table(height)
        {
            strcpy(this->color, color);
        }

        void Show()
        {
            cout<<"高度:"<<Table::Show()<<endl;
            cout<<"面积:"<<Round::Area()<<endl;
            cout<<"颜色:"<<color<<endl;
        }
};


int main()
{
    class RoundTable a("粉色", 4, 20);
    a.Show();
}