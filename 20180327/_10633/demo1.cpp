#include <iostream>

using namespace std;

int main()
{
    unsigned long long int num;
    int num_of_answer;

    while (scanf("%llu", &num) && num)
    {
        num_of_answer = 0;
        cout << num << '\n';
        for(unsigned long long int i = num / 10; i < 1000000000000000000 && num_of_answer < 2 && i < (num * 100); i++){
            if( (num + i) / 10 == i){
                cout << num +i << ' ';
                num_of_answer++;
            }
        }
        cout << '\n';
    }
    
}