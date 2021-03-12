#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l;
    vector<int> x;
    vector<int> y;
    vector<int> buffer;

    while(scanf("%d%d", &n, &l) && n){
        x.clear();
        y.clear();
        buffer.clear();

        while(l--){
            int t1, t2;
            cin >> t1 >> t2;
            x.push_back(t1);
            y.push_back(t2);
        }
        
        buffer.push_back(x[0]);
        buffer.push_back(y[0]);
        x.erase(x.begin());
        y.erase(y.begin());

        int pivot = 0;
        bool keep = true;

        while(pivot != buffer.size() && keep){
            int t = buffer[pivot];

            for(int i = 0; i < x.size() && keep; i++){
                if(t == x[i]){
                    for(int j = 0; j < buffer.size() && keep; j++){
                        if(buffer[j] == y[i]){
                            cout << "NOT BICOLORABLE.\n";
                            keep = false;
                        }
                    }
                    if(keep){
                        buffer.push_back(y[i]);
                        x.erase(x.begin() + i);
                        y.erase(y.begin() + i);
                    }
                }
            }
            pivot++;
        }
        if(keep)
            cout << "BICOLORABLE.\n";
    }
}