#include <iostream>

class Shape
{
    public:
    virtual void area() = 0;
};
class Circle: public Shape
{
    public:
    void area() override
    {
        std::cout <<"Area of Circle" << std::endl;
    }
};
class Rect: public Shape
{
    public:
    void area() override
    {
        std::cout <<"Area of rectangle" << std::endl;
    }
};

int main()
{
    Circle c1;
    Rect r1;
    Shape* s = &c1;
    s->area();
    s = &r1;
    s->area();
}
