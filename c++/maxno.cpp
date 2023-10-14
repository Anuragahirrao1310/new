#include<iostream>
using namespace std;
class ABCC
{
public:
inline int compare(int x, int y, int z)
{
  if(x>y&&x>z)
     cout<<"the first number is bigger";
    else if(y>x&&y>z)
    cout<<"the second number is bigger";
     else
    cout<<"the third number is bigger";
}

int output()
{
    int x,y,z;
    cout<<"enter the first number:";
    cin>>x;
    cout<<"enter the second number:";
    cin>>y;
    cout<<"enter the third number:";
    cin>>z;  
    compare(x,y,z);
    return 0;
}
};
int main()
{
    ABCC a;
    a.output();
}