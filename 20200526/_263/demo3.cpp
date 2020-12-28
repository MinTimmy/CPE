#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;
bool cmd(char a, char b)
{
    return a > b;
}
int main()
{

    set<long long int> same;
    string s;
    while (cin >> s && s != "0"){
        
        stringstream ss(s);
        long long int o1,a1,b1;
        ss >> o1;

        same.clear();
        cout << "Original number was " << o1 << '\n';

        while(1){
            sort(s.begin(), s.end(), cmd);
            stringstream sti1(s);
            sti1 >> a1;

            sort(s.begin(), s.end());
            stringstream sti2(s);
            sti2 >> b1;
            cout << a1 << " - " << b1 << " = " << a1-b1 << '\n';
            if(same.find(a1-b1) != same.end())
                break;
            same.insert(a1-b1);

            stringstream sti3;
            sti3 << a1-b1;
            sti3 >> s;
        }

        cout << "Chain length " << same.size() + 1 << "\n\n";
    }
    
}