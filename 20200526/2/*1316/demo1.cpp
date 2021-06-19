#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


int* findMin(int* a, int bound)
{
    int min = a[bound - 1];
    int* an = &a[bound - 1];
    for(int i = bound - 1; i >= 0; i--){
        if(min > a[i]){
            min = a[i];
            an = a + i;
        }
    }
    return an;
       
}
int main()
{
    int n;
    int answer[10005];
    memset(answer, 0, sizeof(answer));

    while(scanf("%d", &n) != EOF){
        memset(answer, 0, sizeof(answer));
        for(int i = 0; i < n; i++){
            int p, d;
            scanf("%d %d", &p, &d);
            if(p > *findMin(answer, d)){
                *findMin(answer, d) = p;
            }
        }
        int sum = 0;
        cout << accumulate(answer, answer + (sizeof(answer) / sizeof(int)),sum) << '\n';
    }
    
}