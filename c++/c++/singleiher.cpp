#include<iostream>
using namespace std;
class A {
    public:
    int name()
    {
    cout<<"Anurag"<<endl;
    }
};
class B : public A
{

};
int main()
{
    B obj;
    obj.name();
    return 0;
}