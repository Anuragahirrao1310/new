#include <iostream>
using namespace std;

template<class T>
class Vector
{
    T* v;
    int size;
   
public:
    Vector(int n)
    {
      v = new T[n];
      size = n;
    }
    
    ~Vector()
    {
     delete[] v;
    }
    void create()
{
  for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for element " << i << ": ";
        cin >> v[i];
    }  
}
    void modify()
    {
     int index;
    T newval;
    cout << "Enter the index to modify: ";
    cin >> index;
    cout << "Enter the new value: ";
    cin >> newval;
    if (index >= 0 && index < size)
        v[index] = newval;
    else
        cout << "Invalid index." << endl;
    }

    void multiply()
    {
     T scalar;
    cout << "Enter the scalar value: ";
    cin >> scalar;
    for (int i = 0; i < size; i++)
        v[i] = v[i] * scalar;

    }
    void display()
    {
    cout << "Vector elements: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;
    }
};
int main()
{
    int size;
     int ch;
    cout << "Enter the size of the vector: ";
    cin >> size;
    Vector<int> v(size);
    cout<<"\nProgram for template class";
    do
    {
        cout<<"\nMAIN MENU";
        cout<<"\n1.Create";
        cout<<"\n2.modify";
        cout<<"\n3.multiply";
        cout<<"\n0.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;

     switch(ch)
        {
            case 1:
                v.create();
                v.display();
                break;
               
            case 2:
                v.modify();
                v.display();
                break;
               
            case 3:
                v.multiply();
                v.display();
                break;
               
            case 0:
                cout<<"\nExit\n";
                break;
               
            default:
                cout<<"\nInvalid choice";
                break;
        }
    }while(ch!=0);
   return 0;
}
