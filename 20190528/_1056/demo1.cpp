#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<string> tree;
    string temp;
    vector<string> data;
    int p, r;
    int n = 0;


    while(scanf("%d%d", &p, &r) && p != 0){
        int count[61] = {0};
        n++;
        tree.clear();
        temp.clear();
        data.clear();

        for(int i = 0; i < r * 2; i++){
            cin >> temp;
            data.push_back(temp);
            if( i < 2 ){
                tree.insert(data.at(0));
                data.erase(data.begin());
            }
        }
        bool check = 1;
        // for(int i = 0; i < data.size(); i++){
        //     cout << data.at(i) << ' ';
        // }
        // cout << '\n';
        while(check){
            check = 0;
            for(int i = 0; i< data.size(); i++){
                if(tree.find(data.at(i)) != tree.end()){
                    if(i % 2 == 0){
                        check = 1;
                        tree.insert(data.at(i));
                        tree.insert(data.at(i+1));
                        count[i]++;
                        if(tree.find(data.at(i+1)) != tree.end())
                            count[i+1]++;
                        // cout << data.at(i) << '\t' << data.at(i+1) << '\n';
                        data.erase(data.begin() + i, data.begin() + i + 2);
                    }
                    else{
                        check = 1;
                        tree.insert(data.at(i));
                        tree.insert(data.at(i-1));
                        count[i]++;
                        if(tree.find(data.at(i-1)) != tree.end())
                            count[i+1]++;
                        // cout << data.at(i) << '\t' << data.at(i+1) << '\n';
                        data.erase(data.begin() + i - 1, data.begin() + i + 1);
                    }
                    if(i > 2)   
                        i -= 2;
                }
            }
        }
        cout << '\n';
        for(int i = 0; i < data.size(); i++){
            // cout << data.at(i) << ' ';
        }
        cout << "Network " << n << ": ";
        if(tree.size() != p)
            cout << "DISCONNECTED\n";
        else{
            cout << *max_element(count,count + p) << '\n';
        }
        // cout << '\n';
    }
}