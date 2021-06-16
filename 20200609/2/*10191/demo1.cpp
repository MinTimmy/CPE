#include <iostream>
#include <string>

using namespace std;


int getmin(string a)
{
    return ( (a[0] - 48) * 10 + (a[1] - 48) ) * 60 + (a[3] - 48)* 10 + (a[4] - 48);
}
int main()
{
    int n;
    char error;
    string cal[2];
    string input;
    int count = 0;
    while(scanf("%d", &n) != EOF){
    // while(cin >> n){
        // cin >> error;
        getline(cin,input);
        getline(cin,input);
        int max = 0;
        string answer;
        cout << input << '\n';
        answer.assign(input,6,5);
        cal[0].assign(input,6,5);
        cout << answer << '\n';
        while(--n){
            getline(cin,input);
            // cout << "input: " << input << '\n';
            cal[1].assign(input,0,5);
            if(getmin(cal[1]) - getmin(cal[0]) > max){
                max = getmin(cal[1]) - getmin(cal[0]);
                // cout << cal[0] << '\t' << cal[1] << '\n';
                // cout << getmin(cal[1])<<'\n';
                // cout << getmin(cal[0])<<'\n';
                answer = cal[0];
            }
            cal[0].assign(input,6,5);
        }

        cal[1] = "18:00";
        if(getmin(cal[1]) - getmin(cal[0]) > max){
            max = getmin(cal[1]) - getmin(cal[0]);
            answer = cal[0];
        }

        if(!(max/60))
            cout << "Day #" << ++count << ": the longest nap starts at " << answer << " and will last for " << max << " minutes.\n";
        else
            cout << "Day #" << ++count << ": the longest nap starts at " << answer << " and will last for " << max / 60 << " hours and " << max % 60 << " minutes.\n";

    }


}