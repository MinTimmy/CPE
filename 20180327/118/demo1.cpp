#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int edge[2];
    int position[2];
    int orientation;
    string instruction;
    vector<int> scent_x;
    vector<int> scent_y;
    char t1;
    map<char, int>m;
    m['N'] = 0;
    m['E'] = 1;
    m['S'] = 2;
    m['W'] = 3;
    m['R'] = 1;
    m['L'] = -1;

    cin >> edge[0] >> edge[1];
    while(scanf("%d%d %c", position, position+1, &t1) != EOF){
        cin >> instruction;
        orientation = m[t1];
        bool isOut = false;
        for(int index_instruction = 0; index_instruction < instruction.size() && !isOut; index_instruction++){
            
            
            for(int i = 0; i < 1; i++){
                if(position[i] < 0){
                    position[i]++;
                    vector<int>::iterator iter= find(scent_x.begin(), scent_x.end(), position);
                    if(iter == scent_x.end()){
                        isOut = true;
                    }
                }
                if(position[i] > edge[i]){
                    position[i]--;
                } 
                scent_x.push_back(position[0]);
                scent_y.push_back(position[1]);
            }
            
        } 
    }
}