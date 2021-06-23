#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input1", "r", stdin);
    freopen("output1", "w", stdout);

    int k, q,q_next;
    const int dir[][3] = {{1,0,-8}, {-1,0,8}, {0,-1,-1}, {0,1,1}}; // up down left right
    
    while(scanf("%d %d %d", &k, &q, &q_next) != EOF){
        // cout << "k: " << k << "\n";
        int q_p[] = {q / 8 , q %8};
        int k_p[] = {k / 8, k %8};

        int q_next_p[] = {q_next / 8, q_next % 8};

        if(k == q){
            cout << "Illegal state\n";
        }
        else if(k == q_next){
            cout << "Illegal move\n";
        }
        else{
            int t[2];
            bool legal_move = false;
            
            for(int i = 0; i < 4 && !legal_move; i++){
                t[0] = q_p[0];
                t[1] = q_p[1];
                // cout << "i " << i << '\n';
                while( ( t[0] >= 0 && t[0] < 8  &&  t[1] >= 0 && t[1] < 8)) {
                        // cout << "t[0] " << t[0] << '\n';
                        // cout << "t[1] " << t[1] << '\n';
                        t[0] += dir[i][0];
                        t[1] += dir[i][1];
                        if( t[0] == k_p[0] && t[1] == k_p[1]){
                            break;
                        } 
                        if(t[0] == q_next_p[0] && t[1] == q_next_p[1] ){
                            // cout << "hello\n";
                            legal_move = true;
                            break;
                        }
                    }
            }
            if(!legal_move){
                cout << "Illegal move\n";
            }
            else{
                bool check = true;
                for(int i = 0; i < 4; i++){
                    if(q_next_p[0] == k_p[0] + dir[i][0] && q_next_p[1] == k_p[1] + dir[i][1]){
                        cout << "Move not allowed\n";
                        check = false;
                        break;
                    }
                }
                if(check){
                    int count = 0;
                    int q_for[4][2];
                    // cout << "q_p " << q_p[0] << " " << q_p[1] << "\n";
                    for(int i = 0; i < 4; i++){
                        q_for[i][0] = q_next_p[0] + dir[i][0];
                        q_for[i][1] = q_next_p[1] + dir[i][1];
                        // cout << "q_for[" << i << "][0] = " <<  q_for[i][0] << "\tq_for[" << i << "][1] = " << q_for[i][1] << "\n"; 
                    }
                    for(int i = 0; i < 4; i++){
                        t[0] = k_p[0] + dir[i][0];
                        t[1] = k_p[1] + dir[i][1];
                        // cout << i << " t[0] = " << t[0] << '\t' << "t[1] = " << t[1] << '\n';
                        if(t[0] == q_next_p[0] && t[1] == q_next_p[1]){
                            count++;
                        }
                        else if(t[0] < 0 || t[0] >= 8 || t[1] < 0 || t[1] >= 8){
                            // cout << "1\n";
                            count++;
                        }
                        else{
                            for(int j = 0; j < 4; j++){
                                if(q_for[j][0] == t[0] && q_for[j][1] == t[1]){
                                    // cout << "22\n";
                                    count++;
                                    break;
                                }
                            }
                        }
                    }
                    // cout << count << '\n';
                    if(count == 4){
                        cout << "Stop\n";
                    }
                    else{
                        cout << "Continue\n";
                    }
                }
            }

        }
        
        
    }
}