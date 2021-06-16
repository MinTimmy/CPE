#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n)
    {
        int center[2];
        cin >> center[0] >> center[1];

        while(n)
        {
            int point[2];
            cin >> point[0] >> point[1];
            if(point[0] == center[0] && point[1] == center[1])
            {
                cout << "divisa\n";
            }
            else if(point[0] >= center[0] && point[1] >= center[1])
            {
               cout << "NE\n"; 
            }
            else if(point[0] <= center[0] && point[1] >= center[1])    
            {
                cout << "NO\n";
            }
            else if(point[0] <= center[0] && point[1] <= center[1])
            {
                cout << "SO\n";
            }
            else
            {
                cout << "SE\n";
            }
            n--; 
        }
        cin >> n;

    }
}