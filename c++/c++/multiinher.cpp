#include<iostream>
using namespace std;
class A {
    public:
    int name()
    {
    cout<<"Anurag"<<endl;
    }
};
class B
{
    public:
    int name1()
    {
    cout<<"Anu"<<endl;
    }
};
class C : public B , public A 
{  
};
int main()
{
    C obj;
    obj.name();
    obj.name1();
    return 0;
}
