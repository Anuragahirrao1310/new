#include<iostream>
using namespace std;
class student
{
    private:
    string name,address;
    double a;
    int b;
    public:
    void input()
    {
        cout<<"enter the name of the student:";
        cin>>name;
        cout<<"enter the address of the student:";
        cin>>address;
        cout<<"enter the phone number of student:";
        cin>>a;
        cout<<"enter the marks of the student:";
        cin>>b;
    }
    void output()
    {
    cout<<endl<<"the name of the student :"<<name;
    cout<<endl<<"the Address of the student is:"<<address;
    cout<<endl<<"phone number of student is :"<<a;
    cout<<endl<<"the marks of student is :"<<b;
    }
}s;
int main()
{
 s.input();
 s.output();
}