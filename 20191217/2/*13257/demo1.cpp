#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int n = 0;
    cin >> n;

    while(n--){
        cin >> str;
        // cout << str.size() << '\n';
        vector<string> buffer;

        for(int i = 0; i < str.size() - 2; i++){
            for(int j = i+1; j < str.size() - 1; j++){
                for(int k = j + 1; k < str.size(); k++){
                    string temp;
                    temp += str[i]; 
                    temp+= str[j];
                    temp += str[k];
                    // cout << temp << '\n';
                    // cout << "Hello" << '\n';

                    vector<string>::iterator it = find(buffer.begin(), buffer.end(), temp);
                    // cout << "it: " << *(it-1) << '\n';
                    if(it == buffer.end()){
                        buffer.push_back(temp);
                    }
                    ;
                }
            }
        }
        // for(int i = 0; i < buffer.size(); i++){
        //     cout << buffer[i] << '\n';
        // }
        cout << buffer.size() << '\n';
    }
}
