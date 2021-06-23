//uva255
#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, q, m;
    while (scanf("%d %d %d", &k, &q, &m) != EOF) {

        if (k == q) // if the initial point of king and queen are same 
            printf("Illegal state\n");
        else {
            // if q and m are not on the same row or column
            if (q / 8 != m / 8 && q % 8 != m % 8)
                printf("Illegal move\n");
            else {
                // if q does not move
                if (q == m)
                    printf("Illegal move\n");
                
                // if king is on the corner and q is near king
                else if ((k == 0 && m == 9) || (k == 7 && m == 14) || (k == 56 && m == 49) || (k == 63 && m == 54))
                    printf("Stop\n");
                
                // if queen moves vertically and king and moved queen are on the same column
                else if (q / 8 == m / 8 && k / 8 == m / 8) {
                    // if queen moves accross king
                    if ((k - m)*(k - q) <= 0)
                        printf("Illegal move\n");
                    // if moved queen is under or up king in one step
                    else if (m == k + 1 || m == k - 1)
                        printf("Move not allowed\n");
                    else
                        printf("Continue\n");
                }

                // if queen moves horizontally and king and moved queen are on the same row
                else if (q % 8 == m % 8 && k % 8 == m % 8) {
                    // if queen moves accross king
                    if ((k - m)*(k - q) <= 0)
                        printf("Illegal move\n");
                    //  if moved queen is left or right of king in one step
                    else if (m == k + 8 || m == k - 8)
                        printf("Move not allowed\n");
                    else
                        printf("Continue\n");
                }

                // if king and queen are not on the same row or column 
                else {
                    if (((m - 1) / 8 == m / 8 && m - 1 == k) || ((m + 1) / 8 == m / 8 && m + 1 == k))
                        printf("Move not allowed\n");
                    else if(((m - 8) >= 0 && k == m - 8) || ((m + 8) < 64 && k == m + 8))
                        printf("Move not allowed\n");
                    else
                        printf("Continue\n");
                }
            }
        }
    }
    return 0;
}