//uva1583
#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxn 100010
using namespace std;

int ans[maxn];

int main (){
    int x, t;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < maxn; i++){
        x = i;
        t = i;
        while (x > 0){
            t += x%10;
            x /= 10;
        }
        if (i < ans[t] || ans[t] == 0)
            ans[t] = i;
    }
    int in, input;
    cin >> in;
    while (in--) {
        cin >> input;
        cout << ans[input] << endl;
    }
    return 0;
}

