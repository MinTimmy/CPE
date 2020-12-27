#include <iostream>
#include <string>

using namespace std;

string DNA[50];
string answer;
const char ine[5] = "ACGT";
int error;
int row,col;

void input()
{
    cin >> col >> row;

    for(int i = 0; i < col; i++)
        for(int j = 0; j < row; j++)
            cin >> DNA[i][j];
}

void findCS()
{
    error = 0;
    for(int r = 0; r < row; r++)
    {
        int count[4] = {0};
        for(int c = 0; c < col; c++)
        {
            switch (DNA[c][r])
            {
            case 'A':
                count[0]++;
                break;
            case 'C':
                count[1]++;
                break;
            case 'G':
                count[2]++;
                break;
            case 'T':
                count[3]++;
                break;
            }
        }

        int max_ = count[0];
        int max_index = 0;
        for(int i = 1; i < 4; i++)
        {
            if(max_ < count[i])
            {
                max_ = count[i];
                max_index = i;
            }
        }

        for(int i = 0; i < 4; i++)
        {
            if(i != max_index)
            {
                error += count[i];
            }
        }
        cout << ine[max_index];

    }
    cout << '\n' << error << '\n';
    
}
void output()
{
    answer = "";
    findCS();
}
int main()
{
    int n;
    cin >> n;

    while (n)
    {
        input();
        output();
        n--;
    }
    
}