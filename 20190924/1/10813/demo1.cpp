#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int _find(vector<int> ta, int t)
{
    for(int i = 0; i < 25; i++){
        if(ta.at(i) == t)
            return i;
    }
    return -1;
}
int main()
{
    int n;
    int t;
    bool check = 1;
    vector<int> table;
    cin >> n;
    while(n){
        check = 1;
        int row[5] = {0,0,1,0,0};
        int col[5] = {0,0,1,0,0};
        int dia[2] = {1,1};
        int answer = 0;
        table.clear();
        n--;
        // cout << "\n\n--------------------------" << n << "\n\n";
        for(int i = 0; i < 24; i++){
            cin >> t;
            table.push_back(t);
        }
        table.insert(table.begin()+12,-1);
        // cout << "\n\n--------------------------" << table.at(24) << "\n\n";
        for(int i = 0; i < 75 ; i++){
            cin >> t;
            int index = _find(table,t);
            // cout << "\n" << t << " " << index << "\n";
            if(index != -1 && check){
                if(++row[index / 5] == 5){
                    cout << "BINGO after " << i+1 << " numbers announced\n"; 
                    check = 0;
                }
                else if(++col[index % 5] == 5){
                    cout << "BINGO after " <<  i+1<< " numbers announced\n";
                    check = 0;
                }
                else if((index / 5) == (index % 5)){
                    if(++dia[0] == 5){
                        cout << "BINGO after " << i + 1<< " numbers announced\n";
                    check = 0;
                    }
                }
                else{
                    switch (index)
                    {
                        case 4:
                            dia[1]++;
                            // cout << "\n\nhello4\n\n";
                            break;
                        case 8:
                            dia[1]++;
                            // cout << "\n\nhello8\n\n";
                            break;
                        case 16:
                            dia[1]++;
                            // cout << "\n\nhello16\n\n";
                            break;
                        case 20:
                            dia[1]++;
                            // cout << "\n\nhello20\n\n";
                            break;
                    }

                    if(dia[1] == 5){
                        cout << "BINGO after " << i + 1<< " numbers announced\n";
                        check = 0;
                    }
                }
               
            }
            
        }
    }
}