//uva13257
#include <bits/stdc++.h>

using namespace std;
int re[100002]; // 判斷從第 i 項之後出現幾種不同的字母


// 以 NUEVE(13 20 4 21 4) 當作測資
int main() {
    int cas; // 測資數量
    int c[26];
    int seq;
    bool check[26][26];
    vector<int> a[26];
    string s; // 測資

    scanf("%d", &cas); // 輸入測資數量
    getchar();
    while (cas--) {

        // 把 check 所有值都設為0
        for (int i = 0; i<26; i++)
            for (int j = 0; j<26; j++)
                check[i][j] = 0;

        getline(std::cin, s); // 輸入測資

        // 如果測資長度小於 3 就直接輸出 0
        if (s.length()<3) {
            printf("0\n");
            continue;
        }

        memset(c, 0, sizeof(int)*26); // 把整數陣列 c 的值都設成 0
        memset(re, 0, sizeof(int)*100002); // 把整數陣列 re 的值都設成 0

        a[ (int)(s[0]-'A') ].push_back(0); // 把測資的第 1 項質當作 a 的 index 值，並新增 0，紀錄 N (a[13][0] = 0)在第 0 位置
        a[ (int)(s[1]-'A') ].push_back(1); // 把測資的第 2 項質當作 a 的 index 值，並新增 1，紀錄 U (a[20][0] = 1)在第 1 位置

        // 從測資的第 2 項開始到最後一項
        for (int i = 2, j = 0; i<s.length(); i++) {
            
            // a[4][0] = 2, a[21][0] = 3, a[4][1] = 4
            // c[4] = 2, c[21] = 1
            // re[2] = 2


            // 從測資的 i 項知道，這個字母在地幾個位置
            j = (int)(s[i]-'A'); // 把測資的第 i 項質當作 index 值存入 j
            a[j].push_back(i); // 在 a 的第 j 項新增 i ，判斷每個字母在測資中的第幾個位子
            c[j]++; // 在 c 的第 j 項 +1，判斷每個字母在測資中出現幾次

            // 如果有字母只出現一次， re 的第 2 項就 +1
            // 如果 c 的第 j 項是 1，re 的第 2 項 +1
            if (c[j]==1)
                re[2]++;
        }

        // 從測資的第 3 項開始到最後一項
        for (int i = 3, j = 0; i<s.length(); i++) {
            // c[21] = 0, c[4] = 1
            // re[3] = 2, re[4] = 1
            j = (int)(s[i-1]-'A'); // 把測資的第 i - 1 項質當作 index 值存入 j
            c[j]--; // 在 c 的第 j 項 -1
            re[i] = c[j]==0 ? re[i-1]-1 : re[i-1]; // 如果 c 的第 j 項是 0 ，re 的第 i 項就存入

        }

        // 目前 a, c, re 的資料
        // a[13][0] = 0, a[20][0] = 1, a[4][0] = 2, a[21][0] = 3, a[4][1] = 4
        // c[21] = 0, c[4] = 1
        // re[2] = 2, re[3] = 2, re[4] = 1

        for(int i = 0; i < 26; i++){
            int j = 0;
            for(vector<int>::iterator it = a[i].begin(); it != a[i].end(); it++){
                cout << "a[" << char(i + 'A') << i << "][" << j++ << "] = " << *it << '\t';
            }
            if(a[i].size() != 0)
                cout << '\n';
        }

        for(int i = 0; i < 26; i++){
            if(c[i] != 0)
                cout << "c[" << char(i + 'A') << i << "] = " << c[i] << '\n';
        }
        for(int i = 0; i < 100002; i++){
            if(re[i] != 0){
                cout << "re[" << i << "] = " << re[i] << '\n';
            }
        }
        seq = 0; // subsequence 的數量，也是最後的答案

        for (int i = 0; i<26; i++) {
            for (int j = 0; j<26; j++) {
                // 如果 i 等於 j 且 a 的第 i 項不是空的
                if (i == j && a[i].size()>1) {
                    seq+= re[a[j][1]+1];
                }
                else if(i != j && !a[i].empty() && !a[j].empty() && a[j][ a[j].size()-1 ] > a[i][0]) {

                    int k = 0, l = a[j].size(), temp;

                    while (k!=l) {
                        temp = k+(l-k)/2;
                        if (a[j][temp]>a[i][0])
                            l = temp;
                        else
                            k = temp+1;
                    }
                    seq+= re[a[j][k]+1];
                }
            }
        }


        printf("%d\n", seq);
        for (int i = 0; i<26; i++)
            a[i].clear();
    }
    return 0;
}