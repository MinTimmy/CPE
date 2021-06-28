//uva1207
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;

    while (scanf("%d ", &x) != EOF)
    {
        char c1[x + 5];
        gets(c1);
        scanf("%d ", &y);
        char c2[x + 5];
        gets(c2);

        int dp[x][y];
        for (int i = 0; i<y; i++)
        {
            if (c1[0] == c2[i])
            {
                if(i == 0)
                    dp[0][0] = 0;
                else
                    dp[0][i] = dp[0][i - 1];

                for (int j = i + 1; j<y; j++)
                    dp[0][j] = dp[0][i] + j - i;

                break;
            }
            dp[0][i] = i + 1;
        }
        for (int i = 0; i<x; i++)
        {
            if (c2[0] == c1[i])
            {
                if (i == 0)
                    dp[0][0] = 0;
                else
                    dp[i][0] = dp[i - 1][0];

                for (int j = i; j<x; j++)
                    dp[j][0] = dp[i][0] + j - i;

                break;
            }
            dp[i][0] = i + 1;
        }
        for (int i = 1; i<x; i++)
        {
            for (int j = 1; j<y; j++)
            {

                if (c1[i] == c2[j]) dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    if (dp[i - 1][j - 1] <=dp[i - 1][j] && dp[i - 1][j - 1] <=dp[i][j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;

                    else if (dp[i][j - 1] <=dp[i - 1][j] && dp[i][j - 1] <=dp[i - 1][j - 1])
                        dp[i][j] = dp[i][j - 1] + 1;

                    else
                        dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        printf("%d\n", dp[x - 1][y - 1]);
    }
    return 0;
}

