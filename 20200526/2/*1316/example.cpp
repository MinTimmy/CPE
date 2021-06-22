//uva1316
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct item{
    int price, day;
};

bool cmp(const item& a, const item& b){
    return a.price > b.price;
}

int main(){
    int n, ans; // 變數 n 為有幾種不同商品，變數 ans 為最佳的商品價值
    int i, j, k;
    int s[10005]; // 如果 element 是-1代表這天並沒有放商品，可以直接放上去。如果 element 不是-1，此時的 element 值代表要跳到第幾天去 
    item t[10005]; // 不同商品的存取地
    while (scanf("%d", &n) == 1){
        for(i = 0; i < n; i++){
            scanf("%d%d", &t[i].price, &t[i].day);
        }
        sort(t, t+n, cmp); // 利用 price 把商品做 sorting，由大到小
        memset(s, -1, sizeof(s)); // 把 s 所有元素設為 -1
        ans = 0; // 把 ans 先設為 0
        for(i = 0; i < n; i++){
            int v = t[i].day; // 第 i 大的商品的期限
            for(;;){
                // 這天還沒有放商品，直接把商品放上去，在利用 for loop 到下一個商品
                if (s[v] == -1){
                    k = v;
                    break;
                }
                // 如果這天已經有放商品了，就跳到其他更之前的天，去看是否可放商品
                else
                    v = s[v];
            }
            // 如果商品被放到第 0 天，就要放棄掉這個商品。如果不為 0 就把這個商品的 price 加到變數 ans 中 
            if(k){
                ans += t[i].price;
                s[k] = k - 1;
            }
        }
        printf("%d\n", ans); // 輸出最終的答案
    }

}