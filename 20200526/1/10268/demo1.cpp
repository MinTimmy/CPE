#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a;
    char c;
    // while(scanf("%d", &a) != EOF)
    // // while(scanf("%d", &a))
    // {
        while (scanf("%d%c", &a ,&c))
        {
            if(c != ' ')
                break;
            cout << a << '\n';
        }
        

    // }

}