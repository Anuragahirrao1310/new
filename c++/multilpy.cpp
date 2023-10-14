#include<iostream>
using namespace std;
inline int mul(int a, int b)
{
    return(a*b);
}
inline float division( float a, float b)
{
    return(a/b) ;
}
int main()
{
    int x,y;
    cout<<"enter the value of x:";
    cin>>x;
    cout<<"enter the value of y:";
    cin>>y;
    
    cout<<mul(x,y)<<endl;
    cout<<division(x,y)<<endl;
    return 0;
}