#include <iostream>
#include <map>
#include <string>

using namespace std;
#define MAX 9999999
int main()
{
    int p,r;

    while(cin >> p >> r){
        if (p == 0 || r == 0)
            break;

        map<string, int>people;
        int array[p][p] = {MAX};
        int answer[p] = {0};

        int cnt = 0;
        string s1 ,s2;

        for(int i = 0; i < r; i++){
            cin >> s1 >> s2;
            if(people.find(s1) == people.end()){
                people[s1] = cnt;
                cnt++;
            }
            if(people.find(s2) == people.end()){
                people[s2] = cnt;
                cnt++;
            }
            array[people.find(s1)->second][people.find(s2)->second] = array[people.find(s2)->second][people.find(s1)->second];
        }
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
                answer[i]+=array[i][j];
            }
        }
        int max = answer[0];
        for(int i = 1; i < p; i++){
            if(max < answer[i]){
                max = answer[i];
            }
        }
        cout << 
    }
}