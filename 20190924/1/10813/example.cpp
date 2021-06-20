//uva10813
#include <bits/stdc++.h>
using namespace std;

int table[5][5];    
int input[75];     

bool check(int ii, int jj){
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(table[i][j]==-1){
                if(i==ii)       a1++;   
                if(j==jj)       a2++;   
                if(i+j==ii+jj)  a3++;  
                if(i-j==ii-jj)  a4++;   
            }
        }
    }
    if(a1==5||a2==5||a3==5||a4==5)  return true;  
    else                            return false;   
}

bool mark(int id){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(table[i][j]==id){
                table[i][j]=-1;
                return check(i,j);
            }
        }
    }
    return false;
}

int main(){
freopen("l.txt","w",stdout);
    int test = 0;
    cin>>test;
    while(test--){     
        memset(table, 0, sizeof(table));
        table[2][2] = -1;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==2&&j==2)  continue;
                cin>>table[i][j];
            }
        }

        for(int i=0;i<75;i++)   cin>>input[i];

        for(int i=0;i<75;i++){
            if(mark(input[i])){
                printf("BINGO after %d numbers announced\n",i+1);
                break;
            }
        }
    }
    return 0;
}