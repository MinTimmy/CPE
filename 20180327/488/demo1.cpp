#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int a, f;
   
    scanf("%d", &n);
    cout << n << "\n\n";
    while(n--){
        scanf("%d%d", &a,&f);
        int t = 1;
        for(int i = 0; i < a * 2 - 1; i++){
            for(int j = 0; j < t; j++){
                cout << t;
            }
            cout << '\n';
            if(i < a-1) t++;
            else t--;
        }

        for(int k = 0; k < f - 1; k++){
            cout << '\n';
            t = 1;
            for(int i = 0; i < a * 2 - 1; i++){
                for(int j = 0; j < t; j++){
                    cout << t;
                }
                if(k != f - 1)
                    cout << '\n';
                if(i < a-1) t++;
                else t--;
            }
        }
        if(n)
            cout << '\n';
    }
}