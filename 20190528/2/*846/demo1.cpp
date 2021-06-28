#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input1", "r", stdin);
    freopen("output1", "w", stdout);

    int n;
    int x,y;

    cin >> n;

    while(n--){
        cin >> x >> y;
        long long int line = y - x;

        if(line == 0){
            cout << 0 << '\n';
            continue;
        }
        long long int a = 2;
        while(a * (a - 1) < line){
            a++;
        }
        // cout << "a = " << a << '\n';
        if(a * (a-1) - a + 1 >= line){
            cout << (a-1) *2 - 1 << '\n';
            continue;
        }
        cout << (a-1) * 2 << '\n';

    }
}