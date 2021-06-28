#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input1", "r", stdin);
    freopen("output1", "w", stdout);

    int N;
    int r;
    const int INF =99999;
    int TT = 1;

    while(cin >> N >> r && (N != 0 || r != 0)){
        
        vector<string> items;
        int a[N][N];
        int p[N][N];

        // init
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                a[i][j] = INF;
                if(i == j){
                    a[i][j] = 0;
                }
                p[i][j] = j;
            }
        }

        string t[2];
        while(r--){
            cin >> t[0] >> t[1];
            vector<string>::iterator it1 = find(items.begin(), items.end(), t[0]);
            if(it1 == items.end()){
                items.push_back(t[0]);
                it1--;
            }
            vector<string>::iterator it2 = find(items.begin(), items.end(), t[1]);
            if(it2 == items.end()){
                items.push_back(t[1]);
                it2--;
            }
            int index[2];

            it1 = find(items.begin(), items.end(), t[0]);
            it2 = find(items.begin(), items.end(), t[1]);
            index[0] = distance(items.begin(), it1);
            index[1] = distance(items.begin(), it2);
            // cout << "index: " << index[0] << '\t' << index[1] << '\n';
            a[index[0]][index[1]] = 1;
            a[index[1]][index[0]] = 1;
        }
 
        for(int j = 0; j < N; j++){
            for(int i = 0; i < N; i++){
                for(int k = 0; k < N; k++){
                    if((i != j) && (j != k)){
                        if(a[i][k] > a[i][j] + a[j][k]){
                            a[i][k] = a[i][j] + a[j][k];
                            p[i][k] = p[i][j]; 
                        }
                    }
                }
            }
        }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        bool check = true;
        int tmp;
        int ans = 0;
        for(int i = 0; i < N && check; i++){
            for(int j = 0; j < N && check; j++){
                tmp = 1;
                int temp = i;
                if(a[temp][j] >= INF){
                    check = false;
                    cout << "Network " << TT++ << ": DISCONNECTED\n\n";
                    break;
                }
                while(p[temp][j] != j){
                    temp = p[temp][j];
                    tmp++;
                    if(a[temp][j] >= INF){
                        check = false;
                        cout << "Network " << TT++ << ": DISCONNECTED\n\n";
                        break;
                    }
                    // cout << " -> " << items[temp];
                    // cout << "a = " << a[temp][j] << '\n';
                    // if(a[temp][j] >= INF){
                    //     cout << " Can't Go ";
                    //     break;
                    // }
                }
                // cout << " -> " << items[j] << "\n";
            }
            if(check){
                if(tmp > ans){
                    ans = tmp;
                }
            }
        }
        if(check){
            cout << "Network " << TT++ << ": " << ans << "\n\n"; 
        }
        


    }
}