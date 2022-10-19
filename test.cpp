#include <iostream>

bool test()
{
    return 1;
}

int main()
{
    int a = 10;
    int b = 10;
    bool d = 1;

    bool c = a != b && a != b || test();

    std::cout << c << std::endl;

}