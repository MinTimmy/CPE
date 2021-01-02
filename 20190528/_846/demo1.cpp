#include <iostream>

using namespace std;

int main()
{
    int n;
    long long int a, b, c;
    cin >> n;

    while(n--){
        cin >> a >> b;
        c = b - a;
        if(c == 0)
            cout << 0 << '\n';
        else if(c == 1)
            cout << 1 << '\n';
        else if(c == 2)
            cout << 2 << '\n';
        else{
            long long int temp = 2;
            int count = 3;
            for(int i = 2; i < 100000; i++){
                if(temp + i * 1  >= c){
                    cout << count << '\n';
                    break;
                }
                count++;
                if(temp + i * 2 >= c){
                    cout << count << '\n';
                    break;
                }
                count++;
                temp = temp + i * 2;
            }
        }
    }
}