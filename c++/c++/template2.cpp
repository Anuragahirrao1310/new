#include<iostream>
using namespace std;
template <class T>
class add
{
    public:
    T a;
    T b;
 void input()
 {
    cout<<"enter a number"<<endl;
        cin>>a;
        cout<<"enter b number"<<endl;
        cin>>b;
 }
 void output()
 {
    cout<<"the sum is"<<a+b<<endl;
 }
};
int main()
{
    add <int> obj;
    obj.input();
    obj.output();
    add <float> obj1;
    obj1.input();
    obj1.output();
    add <string> obj2;
    obj2.input();
    obj2.output();
    return 0;
}