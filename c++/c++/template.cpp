#include<iostream>
using namespace std;
template <class G>
G input(G a, G b)
{
return a+b;
}
int main()
{
    cout<<input<int>(10,20);
}