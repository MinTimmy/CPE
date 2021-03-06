#include <iostream>

using namespace std;

int main()
{
    int n;
    // long long int sum = 0;
    int sum = 0;

    while(scanf("%d", &n) && n != 0){
        for(int j = 2; j <= n; j++){
            for(int i = 1; i <= j; i++){
                if(j % i == 0){
                    // cout << i << " ";
                    sum += i;
                }
            }
        }
        cout << sum << "\n";
        sum = 0;
    }
}