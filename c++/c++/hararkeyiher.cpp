#include<iostream>
using namespace std;
class A {
    public:
    A()
    {
    cout<<"Anurag"<<endl;
    }
};
class B : public A
{
    public:
    B()
    {
    cout<<"Anu"<<endl;
    }
};
class C 
{
  public:
    C()
    {
    cout<<"rag"<<endl;
    }  
};
class D : public C , public B , public A
{  
};
int main()
{
    D obj;
    return 0;
}