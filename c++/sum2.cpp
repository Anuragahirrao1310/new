#include<iostream>
using namespace std;
inline int sum(int a, int b)
{
    return(a+b);
}
int main()
{
    int x,y;
    cout<<"enter the value of x:";
    cin>>x;
    cout<<"enter the value of y:";
    cin>>y;
    
    cout<<sum(x,y)<<endl;
    return 0;
}