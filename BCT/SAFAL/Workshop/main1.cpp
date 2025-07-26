#include <iostream>

// int main(int argc, char *argv[])
// {
//     std::cout << "Hello " << argv[0] << std::endl;
// }

class Student
{
    private:
    std::string name;
    double marks;

    public:
    void setData(std::string name, double marks)
    {
        this->name = name;
        this->marks = marks;
    }
 
    void display()
    {
        std::cout << "Name: " << name << "\nMarks: " << marks << std::endl;
    }
};

int main()
{
    // std::cout << "Hello world !!!" << std::endl;
    // int a, b;
    // std::cout << "Enter 2 numbers: "<<std::endl;
    // std::cin >> a >> b;
    // if( b== 0)
    // {
    //     return 1;
    // }
    // else{
    //     std::cout << "a % b = " << a/b << std::endl;
    // }
    // return 0;

    // static int i = 0;
    // if( i == 5)
    // return 0;
    // std::cout << i << std::endl;
    // i++;
    // main();

    // int num;
    // std::cin >> num;
    // bool isEven = num % 2 == 0;
    // if (isEven)
    //     std::cout << "Even";
    // else
    //     std::cout << "odd";

    Student s;
    s.setData("Safal Gautam", 99.05);
    s.display();
    return 0;
}