#include <bits/stdc++.h>


using namespace std;

int main()
{
    long long int x;
    long long int temp;
    long long int answer = 0;
    vector <long long int >data;
    char c;

    while(scanf("%lld",&x) != EOF)
    {
        answer = 0;
        while (scanf("%lld%c", &temp, &c))
        {
            if( c != ' ')
                break;
            data.push_back(temp);
        }

        data.push_back(temp);
        // cout << data.size() << '\n';
        // for(int i = 0; i < data.size(); i++)
        // {
        //     cout << data.at(i) << ' ';
        // }
        for(int i = 0; i < data.size()-1; i++)
        {
            // cout << answer << '\n';
            answer += data.at(i) * (data.size() - 1 - i) * pow(x, (data.size() - 2 - i));
        }
        cout << answer << '\n';

        // cout << x;
    }
    
}