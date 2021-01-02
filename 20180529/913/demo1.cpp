#include <iostream>

using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n) != EOF){
        unsigned long long int i = 0;
        unsigned long long int j = 1;
        unsigned long long int t;
        while(1){
            t = ((1 + 1 + i) * j ) / 2; 
            if( -1 + j * 2 >= n)  
                break;
            i+=2;
            j++;
        }
        cout << ' ' << (t * 2 - 3) * 3 << '\n';

    }
}