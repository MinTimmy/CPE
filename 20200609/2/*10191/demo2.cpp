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
        // cout << input << '\n';
        answer.assign(input,6,5);
        // cal[0].assign(input,0,5);
        cal[1].assign(input,6,5);

        // cout << answer << '\n';

        while(--n){
            cal[1].assign(input,6,5);
            getline(cin, input);
            // cout << input << '\n';
            cal[0].assign(input,0,5);
            
            // cout << cal[0] << '\t' << cal[1] << '\n';
            if(getmin(cal[1]) > getmin(cal[0])){
                if(getmin("18:00") - getmin(cal[1]) > max){
                    max = getmin("18:00") - getmin(cal[1]);
                    answer = cal[1];
                    cal[1].assign(input,6,5);
               }
                
            }
            else{
               if(getmin(cal[0]) - getmin(cal[1]) > max){
                //    cout << input << '\n';
                   max = getmin(cal[0]) - getmin(cal[1]);
                   answer = cal[1];
                //    cout << max << '\n';
                   cal[1].assign(input,6,5);
               }
            } 
        }
            cal[1].assign(input,6,5);
            if(getmin("18:00") - getmin(cal[1]) > max){
                // cout << "Final " << cal[1] << '\n';
                max = getmin("18:00") - getmin(cal[1]);
                answer = cal[1];    
            }
       

        if(!(max/60))
            cout << "Day #" << ++count << ": the longest nap starts at " << answer << " and will last for " << max << " minutes.\n";
        else
            cout << "Day #" << ++count << ": the longest nap starts at " << answer << " and will last for " << max / 60 << " hours and " << max % 60 << " minutes.\n";

    }


}