#include <bits/stdc++.h>

using namespace std;
int table[5][5];

bool check(int y, int x)
{
    int c[4];
    memset(c,0,sizeof(c));

    for(int i =0; i < 5; i++){
        if(table[i][i] == -1) c[0]++; 
        if(table[4-i][i] == -1) c[1]++;
        if(table[y][i] == -1) c[2]++;
        if(table[i][x] == -1) c[3]++;
    }
    int* t = find(c,c+4,5);
    if(t == c+4){
        // cout << "answer: " << *t << '\n';
        return true;
    }
        
    return false;
}

bool marked(int num)
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(table[i][j] == num){
                table[i][j] = -1;
                return check(i,j);
            }
        }
    }
    return true;
}

int main()
{
    freopen("input1","r",stdin);
    freopen("output1","w",stdout);
    
    int n;
    cin >> n;

    while(n--){
        
        int num[80];
        for(int i = 0; i < 5; i++){
            for(int j = 0; j <5; j++){
                if(i == 2 && j == 2){
                    table[i][j] = -1;
                }
                else{
                    cin >> table[i][j];
                }
            }
        }

        for(int i = 0; i < 75; i++){
            cin >> num[i];
        }

        bool bingo = true;
        int i;
        for(i = 0; i < 75 && bingo; i++){
            bingo = marked(num[i]);
        }

        cout << "BINGO after "<< i << " numbers announced\n";

    }
}