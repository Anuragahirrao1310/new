cout<<"\nSize of vector is:"<<size;
    cout<<"\nElements in vector are:";
    cout<<"(";
    for(i=0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<")";
}

int main()
{
    int ch;
    vector<int>obj;
    cout<<"\nProgram for template class";
    do
    {
        cout<<"\nMAIN MENU";
        cout<<"\n1.Create";
        cout<<"\n2.Display";
        cout<<"\n3.Mult";
        cout<<"\n4.Modify";
        cout<<"\n0.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
       
        switch(ch)
        {
            case 1:
                obj.create();
                break;
               
            case 2:
                obj.display();
                break;
               
            case 3:
                obj.mult();
                break;
               
            case 4:
                obj.modify();
                break;
               
            case 0:
                cout<<"\nExit\n";
                break;
               
            default:
                cout<<"\nInvalid choice";
                break;
        }
    }while(ch!=0);
    return 0;
}
