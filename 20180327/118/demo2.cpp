#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int table[2];
    int position[2];
    char temp[2];
    int face;
    char F[5] = "NESW";
    string instruction;
    vector<int>scent_x;
    vector<int>scent_y;

    cin >> table[0] >> table[1];

    while(cin >> position[0] >> position[1] >> temp){
        switch (temp[0])
        {
        case 'N':
            face = 0;
            break;
        case 'E':
            face = 1;
            break;
        case 'S':
            face = 2;
            break;
        case 'W':
            face = 3;
            break;
        }
        instruction.clear();
        cin >> instruction;

        bool out = false;
        for(int index_instruction = 0; index_instruction < instruction.size() && !(out); index_instruction++){
            if(instruction[index_instruction] == 'R'){
                face = (face + 1) % 4;
            }    
            else if(instruction[index_instruction] == 'L'){
                face = face - 1;
                if(face < 0)
                    face = 3;
            }
            else{
                switch(face){
                    case 0:
                        position[1]++;
                        break;
                    case 1:
                        position[0]++;
                        break;
                    case 2:
                        position[1]--;
                        break;
                    case 3:
                        position[0]--;
                        break;
                }
                if(position[0] == table[0] || position[0] < 0 || position[1] == table[1] || position[1] < 0){
                    out = true;
                    for(int i = 0; i < scent_x.size(); i++){
                        if(position[0] == scent_x[i] && position[1] == scent_y[i]){
                            switch(face){
                                case 0:
                                    position[1]--;
                                    break;
                                case 1:
                                    position[0]--;
                                    break;
                                case 2:
                                    position[1]++;
                                    break;
                                case 3:
                                    position[0]++;
                                    break;
                            }       
                            out = false;
                        }
                    }
                    if(out){
                        scent_x.push_back(position[0]);
                        scent_y.push_back(position[1]);
                    }
                }
            }
            
        }
        if(out){
            if(position[0] < 0)
                position[0]++;
            if(position[1] < 0)
                position[1]++;
            cout << position[0] << " " << position[1] << " " << F[face] << " LOST\n" ;
        }
        else{
            cout << position[0] << " " << position[1] << " " << F[face] << "\n" ;
        }
    }

}