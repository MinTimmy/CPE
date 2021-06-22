//uva11730
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int prime[1001];
int bfs(int s, int t)
{
    int count[1001] = {};
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int p_idx = 0; prime[p_idx] < now; p_idx++)
        {
            if (!(now%prime[p_idx]))
            {
                int temp = now + prime[p_idx];
                if (count[temp]) // 數字 temp 已經找過所以不在往下找
                    continue;

                if (temp == t) // 找到(num == T) 回傳 count
                    return count[now] + 1;
                else if (temp < t) // 目前(num < T)繼續往下尋找
                {
                    count[temp] = count[now]+1;
                    q.push(temp);
                }
                else // 目前(num > T)停止搜尋，都找不到
                    break;
            }
        }
    }

    return -1;
}

int main(){

    int mark[1001];
    int tim=0,s,t;
    bool notPrime[1001] = { true, true };
    int i, j;

    // 尋找 prime number
    for (i = 2; i <= 32; i++)
        for (j = i + i; j < 1001; j += i)
            notPrime[j] = true;
    int cp = 0;
    for (i = 2; i < 1001; i++)
        if (!notPrime[i])
            prime[cp++] = i;
            
    int Case = 0;
    while (cin>>s>>t && s&&t)
    {
        cout<<"Case "<<++Case<<": ";
        if (s == t)
            cout<<"0"<<endl;
        else
            cout<<bfs(s, t)<<endl;
    }
}