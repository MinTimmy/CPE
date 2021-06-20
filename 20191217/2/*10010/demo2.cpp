#include <stdio.h>
#define toLower(s) ((s>= 'A' && s<= 'Z') ? (s - 'A' + 'a') : s)

int row, col;

void find(char name[], char table[][60])
{
    int direction[][2] = { {0,1} , {0,-1} , {1,0} , {-1,0} , {1,-1} , {1,1} , {-1,1} , {-1,-1}};

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            for(int k = 0; k < 8; k++){
                int x = c;
                int y = r;
                int name_index = 0;
                while(name[name_index] == table[y][x]){
                    x += direction[k][1];
                    y += direction[k][0];
                    name_index++;
                    if(name[name_index] == '\0'){
                        printf("%d %d\n",r + 1, c + 1);
                        return;
                    }
                    if(x < 0 || y < 0 || x >= col || y >= row){
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    while(n--){
        
        char table[60][60];
        char name[60];

        scanf("%d %d", &row, &col);
        for(int r = 0; r < row; r++){
           scanf("%s", &table[r]);
           for(int c = 0; c < col; c++){
               table[r][c]  = toLower(table[r][c]);
           }
        }
        int k;
        scanf("%d", &k);
        for(int i = 0; i < k; i++){
            scanf("%s", &name);
            for(int j = 0; name[j]; j++){
                name[j] = toLower(name[j]);
            }
            find(name, table);
        }
        if(n)
            puts("");
    }
}