#include<iostream>
using namespace std;
class complex 
{
    int x , y;
    public:
    void input()
    {
        cout<<"enter a number"<<endl;
        cin>>x;
        cout<<"enter a complex number"<<endl;
        cin>>y;
    }
    complex operator *(complex obj)
    {
        complex A;
        A.x=(x*obj.x)-(y*obj.y);
        A.y=(x*obj.y)+(y*obj.x);
        return A;
    }
    void print()
    {
        cout <<x<<"+"<<y<<"i"<<"\n";
    }
};
int main()
{
complex x1, y1, product; 
x1.input();
cout << "\n Entered values are: \n";
cout << " \t";
x1.print(); 
y1.input();
cout << "\n Entered values are: \n";
cout << " \t";
y1.print(); 
product = x1 * y1; 
cout << "\n The product of two complex numbers is: ";
product.print();
return 0;
}
