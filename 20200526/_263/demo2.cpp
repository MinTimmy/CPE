#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>
using namespace std;

bool cmd(char a, char b)
{
    return a > b;
}
int main()
{
    string s;
    stringstream ss;
    long long int num1, num2, answer;
    set<long long int> same;
    while (getline(cin, s) && s != "0"){
        int c = 0;
        num1 = 0;
        num2 = 0;
        answer = 0;
        same.clear();
        cout << "Original number was " << s << '\n';
        while(1){
            c++;
            sort(s.begin(),s.end(), cmd);
            stringstream st1(s);
            st1 >> num1;
            sort(s.begin(), s.end());
            stringstream st2(s);
            st2 >> num2;

            answer = num1 - num2;
            cout << num1 << " - " << num2 << " = " << answer << '\n';
            if(same.find(answer) != same.end()){
                break;
            }

            same.insert(answer);
            stringstream sti;
            sti << answer;
            sti >> s;
        }
        cout << "Chain length " << same.size()+1 << "\n\n";
    }
    
}