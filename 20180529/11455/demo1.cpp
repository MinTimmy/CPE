#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n){
        n--;

        int n[4];

        for(int i = 0; i < 4; i++){
            cin >> n[i];
        }
        sort(n,n+4);

        if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[0] == n[2] && n[1] == n[3] && n[0] == n[3]){
                cout << "square\n";
        }
        else if(n[0] == n[1] && n[2] == n[3])
            cout << "rectangle\n";
        else if(n[3] < n[0] + n[1] + n[2])
            cout << "quadrangle\n";
        else
            cout << "banana\n";
    }
    
}