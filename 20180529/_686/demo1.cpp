#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> prime_number;
    int n;
    bool isPrime = false;
    bool isAnswer;
    while(cin >> n && n != 0){
        int answer = 0;
        for(int i = 2; i < n; i++){
            for(int j = 2; j <= i; j++){
                isPrime = true;
                isAnswer = false;
                if(i % j == 0){
                    isPrime = false;
                }
                if(isPrime){
                    for(int k = 2; k < n - i; k++){
                        for(int l = 2; l <= k; l++){
                            if(k % l != 0){
                                isAnswer = true;
                            }
                        }
                    }
                }
                if(isAnswer)
                    answer++;
            }
        }
        cout << answer << '\n';
    }
    // for(int i = 0; i < prime_number.size(); i++){
    //     cout << i << ' ';
    // }
}