#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n;
    vector<string> name;
    vector<int> low;
    vector<int> high;
    cin >> n;
    while (n)
    {
        n--;
        int nd;
        cin >> nd;
        string s;
        int temp;
        name.clear();
        low.clear();
        high.clear();

        while (nd)
        {
            nd--;
            cin >> s;
            name.push_back(s);

            cin >> s;
            stringstream ss1(s);
            ss1 >> temp;
            low.push_back(temp);

            cin >> s;
            stringstream ss2(s);
            ss2 >> temp;
            high.push_back(temp);
        }

        cin >> nd;
        while (nd)
        {
            nd--;
            cin >> temp;
            int check = -1;
            for(int i = 0; i < low.size(); i++){
                if(low.at(i) <= temp ){
                    if(high.at(i) >= temp){
                        if(check == -1){
                            check = i;
                        }
                        else if(check != -1){
                            check = -1;
                            break;
                        }
                    }
                }
            }

            if(check != -1){
                cout << name.at(check) << '\n';
            }
            else{
                cout << "UNDETERMINED\n";
            }


        }
        
        cout << '\n';
        
    }
    
}