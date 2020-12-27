#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tablelength[2];
    int count = 0;
    // cout << "hello";
    cin >> tablelength[0] >> tablelength[1];
    // scanf("%d %d", tablelength[0], tablelength[1]) &&
    while ( tablelength[0])
    {
        string table[100];
        int answer[100][100] = {0};
        count++;
        // cout << tablelength[0] << ' ' << tablelength[1];
        for(int i = 0; i < tablelength[0]; i++)
        {
            cin >> table[i];
        }
        for(int i = 0; i < tablelength[0]; i++)
        {
            for(int j = 0; j < tablelength[1]; j++)
            {
                if(table[i][j] == '*')
                {
                    answer[i][j] = -20;
                    if(i-1 >= 0 )
                        answer[i-1][j]++;
                    if(i-1 >= 0 && j + 1 < tablelength[1])
                        answer[i-1][j+1]++;
                    if(j+1 < tablelength[1])
                        answer[i][j+1]++;
                    if(i+1 < tablelength[0] && j+1 < tablelength[1])
                        answer[i+1][j+1]++;
                    if(i+1 < tablelength[0])
                        answer[i+1][j]++;
                    if(i+1 < tablelength[0] && j-1 >= 0)
                        answer[i+1][j-1]++;
                    if(j-1 >= 0)
                        answer[i][j-1]++;
                    if(i-1 >= 0 && j-1 >= 0)
                        answer[i-1][j-1]++;
                }
            }
        }
        cout << "Field #" << count << ":\n";
        for(int i = 0; i < tablelength[0]; i++)
        {
            for(int j = 0; j < tablelength[1]; j++)
            {
                if(answer[i][j] < 0)
                    cout << '*';
                else
                    cout << answer[i][j];
            }
            cout << '\n';
        }
     cin >> tablelength[0] >> tablelength[1];
       
    cout << '\n';
    } 
}