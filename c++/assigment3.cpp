#include <iostream>

using namespace std;
class complex{
    int real,img;
    
    public:
    complex(){
        real=0;
        img=0;        
        
    }
    void putdata(){
        cout<<"The complex number is "<<real<<"+"<<img<<"i"<<endl;
    }
    complex(int r , int i){
        real=r;
        img=i;
    }
    complex(complex&x)
    {
        real=x.real;
        img=x.img;
    }
};
int main()
{
    complex cc;
     cc.putdata();
   complex aa(5,3);
   
   
   complex bb=aa;
  
   aa.putdata();
   bb.putdata();
   
   

   return 0;
}