#include <iostream>
using namespace std;
class MyClass {
public:
    MyClass() 
    {
        count++;
    }
    void displayCount() 
    {
        cout<<"Number of objects created:"<<count<<endl;
    }
private:
    static int count;
};
int MyClass::count= 0;
int main() 
{
    MyClass obj1, obj2, obj3;
    obj1.displayCount();
    return 0;
}