#include <iostream>
using namespace std;
class measure {
    private:
    int feet;
    int inches;
    public:
    measure()
    {
        feet=0;
        inches=0;
    }
    measure(int f, int i)
    {
        feet= f ;
        inches= i ;
    }
    measure add(measure m2)
    {
        measure result;
        result.feet = feet + m2.feet;
        result.inches = feet + m2.feet;
    if(result.inches >= 12)
    {
    result.feet += result.inches/12;
    result.inches %= 12;  
    }
    return result;
    }
    void display(){
        cout<< feet <<"feet "<<inches<<"inches"<<endl;
    }
};
int main(){
    measure m1(4,6);
    measure m2(5,10);
    measure result = m1.add(m2);
    cout << "result";
    result.display();
    return 0;
}