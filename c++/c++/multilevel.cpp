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
public:
    int name1()
    {
    cout<<"Anu"<<endl;
    }
};

class C : public B
{
public:
    int name2()
    {
    cout<<"rag"<<endl;
    }
};
class D : public C
{

};
int main()
{
    D obj;
    obj.name();
    obj.name1();
    obj.name2();
    return 0;
}