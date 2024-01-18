#include <iostream>

class MyClass {
public:
    static int StaticData;
    int NonStaticData;
    
    MyClass(int data) : NonStaticData(data) {}
};

int MyClass::StaticData = 0;

int main() 
{
    MyClass obj1(1);
    MyClass obj2(2);

    std::cout << "obj1 static data: " << obj1.StaticData << std::endl;
    std::cout << "obj2 static data: " << obj2.StaticData << std::endl;

    MyClass::StaticData = 42;

    std::cout << "obj1 static data: " << obj1.StaticData << std::endl;
    std::cout << "obj2 static data: " << obj2.StaticData << std::endl;

    return 0;
}