#include <iostream>

using namespace std;

int main()
{
    int prime[32769] = {0};
    int n;
    int answer = 0;

    for(int i = 2; i <= 32768; i++){
        if(prime[i] == 0){
            for(int j = i; i * j <= 32768; j++){
                prime[i * j] = 1;
            }
        }
    }
    while(scanf("%d", &n) && n != 0){
        answer = 0;
        for(int i =2; i <= n / 2; i++){
            if(prime[i] == 0 && prime[n - i] == 0){
                answer++;
            }
        }
        cout << answer << '\n';
    }
}