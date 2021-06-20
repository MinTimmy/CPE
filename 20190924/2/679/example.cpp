//uva679
#include <iostream>

using namespace std;

int main()
{
    int n,D,I;

    while (cin >> n && n!=-1) {
        while(n--) {

            cin>>D>>I;
            int root = 1;
            for(int i=1; i<=D; i++)
            {
                if((I%2)==0){ 
                    root = 2*root+1; I=I/2;

                }else{ 
                    root = 2*root; I = (I+1)/2;
                }
            }
            cout<<root/2<<endl;
        }
    }
    return 0;
}