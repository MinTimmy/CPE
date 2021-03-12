#include <iostream>

using namespace std;

int main()
{
    long long int n;

    while(scanf("%lld", &n) && n){
        int f = 1;
        long long int answer = 0;
        while(f <= n){
            answer += f * (n / f);
            f++;
        }
        cout << answer - 1 << '\n';
        answer = 0;
    }
}