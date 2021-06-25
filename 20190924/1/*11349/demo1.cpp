#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input1","r",stdin);
    freopen("output1", "w",stdout);
    int n;
    cin >> n;
    
    int nn = 1;
    while(nn <= n){
        char a;
        char b;
        long long int size;
        cin >> a >> b >> size;
        long long int matrix[100][100];

        bool check = true;
        if(size == 1){
            cin >> size; 
            check = false;
            if(size > 0)
                check = true;
            size = 0;
           
        }
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cin >> matrix[i][j];
                if(matrix[i][j] < 0){
                    check = false;
                }
            }
        }

        double center[2];
        if(size % 2 == 0){
            center[0] = size / 2 - 0.5;
            center[1] = size / 2 - 0.5;
        }
        else{
            center[0] = size / 2;
            center[1] = size / 2;
        }
        
        
        for(int i = 0; i < size && check; i++){
            for(int j = 0; j < size; j++){
                int x = j + 2 * (center[1] - j);
                int y = i + 2 * (center[0] - i);

                if(matrix[i][j] != matrix[y][x]){
                    check = false;
                    break;
                }
            }
        } 
        cout << "Test #" << nn++ <<  (check? ": Symmetric.\n" : ": Non-symmetric.\n" );
    }
}