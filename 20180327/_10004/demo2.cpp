#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    int l;

    while(scanf("%d%d", &n, &l) && n){
        vector<int> data_x;
        vector<int> data_y;
        int temp;
        while(n--){
            cin >> temp;
            data_x.push_back(temp);
            cin >> temp;
            data_y.push_back(temp);
        }

        for(int i = 0; i < data_x.size(); i++){
            for(int j = 0; j < data_x.size(); j++){

            }
        }

    }
}