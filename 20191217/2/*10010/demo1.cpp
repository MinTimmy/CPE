#include <bits/stdc++.h>

using namespace std;

string letters[50];
vector<position> answer_p;
int row, col;

struct position
{
    int x;
    int y;
};

bool find_p(string name, position init, int a, int b)
{
    for(int i = 1; i < name.size() - 1; i++){
        
    }
}
int main()
{
    int n = 0;

    cin >> n;

    while (n--)
    {
        string t; 
        
        getline(cin,t); 
        cin >> row >> col;
        cout << t << row << col;
        

        for(int i = 0; i < row; i++){
            cin >> letters[i];
            transform(letters[i].begin(), letters[i].end(), letters[i].begin(), ::toupper);
        }        
        int n_name;
        string name;

        for(int i = 0; i < n_name; i++){
            cin >> name;
            transform(name.begin(), name.end(), name.begin(), ::toupper);

            
            // answer_p.clear();
            bool check = true;
            for(int r = 0; r < row && check; r++){
                for(int c = 0; c < col; c++){
                    if(letters[r][c] == name[0]){
                        position init;
                        init.x = c;
                        init.y = r;
                        // left
                        check = find_p(name, init, -1 ,0);
                        if(!check)
                            break;
                        // right
                        check = find_p(name, init, 1 ,0);
                        if(!check)
                            break;
                        // up
                        check = find_p(name, init, 0 ,1);
                        if(!check)
                            break;
                        // down
                        check = find_p(name, init, 0 ,-1);
                        if(!check)
                            break;
                        // left up
                        check = find_p(name, init, -1 ,1);
                        if(!check)
                            break;
                        // left down
                        check = find_p(name, init, -1 ,-1);
                        if(!check)
                            break;
                        // right up
                        check = find_p(name, init, 1 ,1);
                        if(!check)
                            break;
                        // right down
                        check = find_p(name, init, 1 ,-1);                       
                        if(!check)
                            break;
                    }
                }
            }
        }




    }
    
}