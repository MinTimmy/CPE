#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--){
        int card[25];
        bool marker[5][5];
        int num[80];
        memset(marker, 0 , sizeof(marker));

        for(int i =0; i < 25; i++){
            if(i != 12)
                cin >> card[i];
            else
                card[12] = -1;
        }
        for(int i = 0; i < 75; i++){
            cin >> num[i];
        }

        marker[2][2] = 1;
        for(int i = 0; i < 75; i++){
            int* pos = find(card, card + 25, num[i]);
            if(pos != card + 25){
                int index = pos - card;
                int row = index / 5;
                int col = index % 5;
                marker[row][col] = 1;
                
                bool check = false;
                int j = 0;
                for(j; j < 5; j++){
                    if(marker[row][j] == 0)
                        break;
                }
                if(i == 5){
                    cout << "BINGO after " << i << " numbers announced\n";
                    break;
                }
                j = 0;
                for(j; j < 5; j++){
                    if(marker[j][col] == 0)
                        break;
                }
                if(i == 5){
                    cout << "BINGO after " << i << " numbers announced\n";
                    break;
                }
                
                if(row == col){
                    
                }
            }
        }

    }
}