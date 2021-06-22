#include <bits/stdc++.h>

using namespace std;

int s, t;
int answer = 0;

vector<int> findPrimeFactor(int n)
{
    vector<int> primeFactor; 
    if(n % 2 == 0){
        primeFactor.push_back(2);
        n /= 2;
    }
    while(n % 2 == 0){
        n /= 2;
    }

    for(int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            primeFactor.push_back(i);
            n /= i;
        }
    }
    if(n > 2)
        primeFactor.push_back(n);
    return primeFactor;
}

void F(int n, int count)
{
    // cout << "n: " << n << "\t t: " << t << '\n';
    if(n > t)
        return;
    if ( n == t){
        // cout << "same: count: " << count << "\t answer" << answer << '\n';
        if(count < answer){
            answer = count;
        }
        return;
    }
        
    vector<int> PrimeFactor = findPrimeFactor(n);
    for(int i = 0; i < PrimeFactor.size(); i++){
        // cout << "New node," << count  + 1 << " " <<n + PrimeFactor[i] << '\n';
        F(n+PrimeFactor[i], count + 1);
    }
}
int main()
{
    
    int Case = 0;
    while (scanf("%d%d", &s,&t) || s != 0 )
    {
        answer = 99999;
        
        F(s,0);
        if(answer == 99999)
            answer = -1;
        cout << "Case " << ++Case << ": " << answer << '\n';
    }
    
}