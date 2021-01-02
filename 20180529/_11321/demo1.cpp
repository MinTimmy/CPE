#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool CMP(pair<int, int>&a, pair<int, int>&b)
{
    return a.second < b.second;
}
bool CMP2(pair<int, int>&a, pair<int, int>&b)
{
    return a.first > b.first;
}
bool CMP1(pair<int, int>&a, pair<int, int>&b)
{
    return a.first < b.first;
}
int main()
{
    int n, m;
    int temp;
    vector<pair<int, int>>data;

    while(cin >> n >> m){
        data.clear();
        cout << n << ' ' << m << '\n';
        if(n == 0 && m == 0)
            break;

        for(int i = 0; i < n; i++){
            cin >> temp;
            pair<int, int>a;
            a.first = temp;
            a.second = temp % m;
            auto &it = a;
            data.push_back(it);
        }
        sort(data.begin(), data.end(), CMP);        
        // for(int i = 0; i < data.size(); i++){
        //     cout << data.at(i).first << ' ' << data.at(i).second << '\n' ;
        // }
        temp = data.at(0).first;
        int f = 0;
        for(int i = 1; i < data.size(); i++){
            if(temp != data.at(i).second){
                int k = i - 1;
                pair<int, int> t;
                for(int j = 0; j < i; j++){
                    if(data.at(j).first % 2 == 0){
                        if(data.at(k).first % 2 == 1){
                            t = data.at(j);
                            data.at(j) = data.at(k);
                            data.at(k) = t;
                            if(--k == j)
                                break;
                        }
                        else{
                            if(--k == j)
                                break;
                        }
                    }
                }
                sort(data.begin() + f, data.begin() + k + 1, CMP1);
                sort(data.begin() + k + 1, data.begin() + i, CMP2);
                f = i;
                temp = data.at(i).second;
            }
        }
        for(int i = 0; i < data.size(); i++){
            cout << data.at(i).first << '\n';
        }
    }
}