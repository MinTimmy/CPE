//uva10813
#include <bits/stdc++.h>
using namespace std;

int table[5][5];    
int input[75];     

// 判斷是否有連線
bool check(int ii, int jj){
    // ii 和 jj 是搜尋數字的座標
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0; // a1 a2 a3 a4 是 判斷 row column diagonal 是否有連線
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5; j++){
            // 判斷是否有連線， -1 代表這個格子有被畫記
            if(table[i][j] == -1){
                if(i == ii)       a1++; // 判斷 row 是否有連線
                if(j == jj)       a2++; // 判斷 column 是否有連線
                if(i + j == ii + jj)  a3++; // 判斷右上到左下的對角線 
                if(i - j == ii - jj)  a4++; // 判斷左上到右下的對角線
            }
        }
    }
    // a1 a2 a3 a4 如果等於 5 代表有連線
    if(a1 == 5 || a2 == 5 || a3 == 5 || a4 == 5)  return true;  
    else                            return false;   
}

bool mark(int id){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(table[i][j] == id){
                table[i][j] = -1;
                return check(i,j);
            }
        }
    }
    return false;
}

int main(){
    freopen("l.txt","w",stdout);
    int test = 0;

    cin >> test; // 輸入測資數
    while(test--){     
        memset(table, 0, sizeof(table)); // 把 table 的值都設成 0
        table[2][2] = -1; // 把 table[2][2] 設成 -1，代表這個格子已經被畫記
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(i == 2 && j == 2)  continue; // a[2][2]不輸入數字
                cin >> table[i][j];
            }
        }

        for(int i = 0; i < 75; i++)   cin >> input[i]; // 1 ~ 75 的輸入順序

        for(int i = 0; i < 75; i++){
            // 每標記一個格子就檢測是否有連線
            if(mark(input[i])){
                printf("BINGO after %d numbers announced\n",i+1);
                break;
            }
        }
    }
    return 0;
}