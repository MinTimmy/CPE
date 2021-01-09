#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, temp;

    while(scanf("%d", &n) && n != 0){
        while(scanf("%d", &temp) && temp != 0){
            stack<int> train;
            stack<int> station;
            int t[n];
            t[0] = temp;
            for(int i = 1; i < n; i++){
                cin >> t[i];
            }
            for(int i = n - 1; i >= 0; i--){
                train.push(t[i]);
            }
            bool check = true;
            int train_index = 1;
            while(!train.empty() && check){
                check = false;
                if( train.top() != train_index ){
                    if(station.empty()){
                        check = true;
                        station.push(train_index);
                        train_index++;
                    }
                    else if(station.top() != train.top() && train_index <= n){
                        check = true;
                        station.push(train_index);
                        train_index++;
                    }
                    else if(station.top() == train.top() ){
                        check = true;
                        station.pop();
                        train.pop();
                    }
                }
                else{
                    check = true;
                    train_index++;
                    train.pop();
                }
            }
            if(check){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
    
        }
        cout << '\n';
    }
}