

    #include <iostream>
    using namespace std;
    int main()
    {
        int A[10];
        int x;
        int contok=0;
        int contno=0;
        for( int i=0;i<=9;i++ )
            {
                cin>>A[i];
            }
        cin>>x;
        for( int i=0;i<9;i++ )
            {
                if(A[i]%x==0)
                  {
                    cout<<"NO";
                    break;
                  }
                else
                  {
                    cout<<"OK";
                    break;
                  }
            }
    return 0;
    }

