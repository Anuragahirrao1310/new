// given two int n and k return all combination of k number chossen from range 1 to n //
#include<iostream>
using namespace std ;
void nnumber(int n ,int k)
{
 for (int i = 1 ; i <= n ; i++){
    cout<<k<<i<<endl;
 }
}
int main()
{
int n ,k ;
cout<<"enter the value of N :";
cin>>n;
cout<<"enter the value of K :";
cin>>k;
nnumber(n , k);
}