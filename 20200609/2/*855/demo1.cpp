#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n--){
        double s,a,f;
        double t1, t2;
        double sum1 = 0;
        double sum2 = 0;

        cin >> s >> a >> f;
        
        for(int i = 0; i < f; i++){
            cin >> t1 >> t2;
            sum1 += t1;
            sum2 += t2;
        }

        double t = sum1 / f;
        cout << t << '\n';
        // while(true){
        //     t *= 10;
        //     if((int(t) % 10) > 5){
        //         cout << int(sum1 / f) + 1 << ' ';
        //         break;
        //     }
        //     else if((int(t) % 10) < 5){
        //         cout << int(sum1 / f) << ' '; 
        //         break;
        //     }
        // }
        t = sum2 / f;
        cout << t << '\n';
        // while(true){
        //     t *= 10;
        //     if((int(t) % 10) > 5){
        //         cout << int(sum2 / f) + 1 << '\n';
        //         break;
        //     }
        //     else if((int(t) % 10) < 5){
        //         cout << int(sum2 / f) << '\n'; 
        //         break;
        //     }
        // }    
    }
}