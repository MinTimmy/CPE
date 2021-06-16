#include <iostream>
#include <string>
#include <vector>

using namespace std;


int getmin(string a)
{
    return ( (a[0] - 48) * 10 + (a[1] - 48) ) * 60 + (a[3] - 48)* 10 + (a[4] - 48);
}
int main()
{
    int n;
    char error;
    vector<int> temp[2];
    string input;
    string t;
    int count = 0;
    while(scanf("%d", &n) != EOF){
    // while(cin >> n){
        // cin >> error;
        getline(cin,input);
        getline(cin,input);
        int max = 0;
        string answer;
        vector<string> time;
        temp[0].clear();
        temp[1].clear();

        t.assign(input,0,5);     
        temp[0].push_back(getmin(t));
        t.assign(input,6,5);
        temp[1].push_back(getmin(t));
        time.push_back(t);
        
        while(--n){
            getline(cin,input);
            t.assign(input,0,5);

            int i;
            for(i = 0; i < temp[0].size(); i++){
                if(temp[0][i] > getmin(t)){
                    temp[0].insert(temp[0].begin()+i, getmin(t));
                    break;
                }
            }
            if(temp[0].size() == temp[1].size()){
                temp[0].push_back(getmin(t));
                t.assign(input,6,5);
                time.push_back(t);
                temp[1].push_back(getmin(t));
            }
            else{
                t.assign(input,6,5);
                time.push_back(t);
                temp[1].insert(temp[1].begin()+i, getmin(t));
            }       
        }   

        answer = time[0];
        for(int i = 0; i < temp[0].size() - 1; i++){
            if(temp[0][i+1] - temp[1][i] > max){
                max = temp[0][i+1] - temp[1][i];
                answer = time[i];
            }
        }

        if(getmin("18:00") - temp[1][temp[1].size()-1] > max){
            max = getmin("18:00") - temp[1][temp[1].size()-1];
            answer = time[temp[1].size()-1];
        }
        // for(int i = 0; i < temp[0].size(); i++){
        //     cout << temp[0][i] << '\t' << temp[1][i] << '\n';
        // }
        // cout << "--------------------------------------\n";



        if(!(max/60))
            cout << "Day #" << ++count << ": the longest nap starts at " << answer << " and will last for " << max << " minutes.\n";
        else
            cout << "Day #" << ++count << ": the longest nap starts at " << answer << " and will last for " << max / 60 << " hours and " << max % 60 << " minutes.\n";

    }


}