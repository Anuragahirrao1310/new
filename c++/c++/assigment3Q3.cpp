#include<iostream>
using namespace std;
class LFC
{
    int id;
    static int count;
    public:
    LFC()
    {
        count++;
        id= count;
        cout<<"constructor for id "<<id<<endl;
    }
  ~LFC(){
    cout<<" destructor for id "<<id<<endl;
  }
};
int LFC::count=0;
int main() {
    LFC a[3];
    return 0;
}