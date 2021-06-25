#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    int t = 0;
    string s;
    vector<string> vs;
    cin >> n;
    getline(cin,s);
    getline(cin,s);
    while(n--){
        cout << "Case #" << ++t << ":\n";
        getline(cin,s);
        // getline(cin,s);
        // cout << s << '\n';
        string buffer;
        while( s != ""){
            // cout <<  "\n\n" << s << "\n\n";
            buffer.clear();
            vs.clear();
            for(int i = 0; i < s.size(); i++){
                if(s[i] == ' '){
                    vs.push_back(buffer);
                    // cout << "\n\n" << buffer << "\n\n";
                    buffer = "";
                }
                else
                    buffer += s[i];
            }
                vs.push_back(buffer);
            int count = 0;
            for(int i = 0; i < vs.size(); i++){
                if(vs.at(i).size() > count){
                    cout << vs.at(i)[count];
                    count++;
                }
            }
            cout << '\n';
            s.clear();
            getline(cin,s);
        }
        cout << '\n';
    }
}
