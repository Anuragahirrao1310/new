#include<iostream>
using namespace std;
class pactient
{
    private:
    string name;
    int b,c,d,e,f;
    public:
    void input()
    {
        cout<<"enter the name of the pactient"<<endl;
        cin>>name;
        cout<<"enter the bill amount of the pactient"<<endl;
        cin>>b;
        cout<<"enter the date:";
        cin>>c;
        cout<<"enter the month:";
        cin>>d;
        cout<<"enter the year:";
        cin>>e;
    }
    void output()
    {
    cout<<endl<<"the name of the pactient:"<<name;
    cout<<endl<<"the pactient date of appointment"<<c<<d<<e;
    cout<<endl<<"the bill amount od pactient is :"<<b;
    }
}p;
int main()
{
 p.input();
 p.output();
}