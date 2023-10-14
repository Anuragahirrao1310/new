#include<iostream>
using namespace std;
class complex_num
{
    int x,y;
    public:
    void input()
    {
        cout<<"enter to input complex number "<<endl;
        cin>>x>>y;
    }
    complex_num operator + (complex_num obj)
    {
        complex_num A;
        A.x=x + obj.x;
        A.y=y + obj.y;
        return A;
    }
    void print()
    {
        cout<<x<<"+"<<y<<"i"<<endl;
    }
};
int main()
{
complex_num x1, y1, sum; 
x1.input();
cout << "\n Entered values are: \n";
cout << " \t";
x1.print(); 
y1.input();
cout << "\n Entered values are: \n";
cout << " \t";
y1.print(); 
sum = x1 + y1; 
cout << "\n The addition of two complex numbers is: ";
sum.print();
return 0;
}



