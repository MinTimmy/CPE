#include <bits/stdc++.h>

using namespace std;
string temp;
vector<int> num1; //789 small
vector<int> num2; //987 big
vector<int> answer;
vector<int> previous_answer;

void input()  
{
    num1.clear();
    num2.clear();
    answer.clear();
    previous_answer.clear();
    for(int i = temp.size()-1; i >= 0; i--){
        num1.push_back(int(temp[i])-48);
    }
}

void cal()
{
    sort(num1.begin(),num1.end());

    num2 = num1;
    reverse(num2.begin(), num2.end());
    // for(int i = 0; i < num2.size(); i++)
        // cout << num2.at(i) << ' ';
        
    int carry = 0;
    for(int i = 0; i < num1.size(); i++){
        if(num1.at(i) - num2.at(i) - carry < 0){
            answer.push_back(num1.at(i) - num2.at(i) + 10 - carry);
            // cout << num1.at(i) << ' ' << num2.at(i) << ' ' << answer.at(i) << '\n';
            carry = 1;
        }
        else{
            answer.push_back(num1.at(i) - num2.at(i) - carry);
            // cout << num1.at(i) << ' ' << num2.at(i) << ' ' << answer.at(i) << '\n';
            carry = 0;
        }
        
    }
    
    for(int i = num1.size() - 1; i >= 0; i--){
        if(i != num1.size() - 1)
            cout << num1.at(i);
        else if(num1.size() == 1)
            cout << num1.at(0);
        else
        {
            if(num1.at(answer.size() - 1) != 0)
                cout << num1.at(answer.size() - 1);
        }
        

    }
    cout << " - ";
    for(int i = num2.size() - 1; i >= 0; i--){
        if(i != num2.size() - 1)
            cout << num2.at(i);
        else if(num2.size() == 1)
            cout << num2.at(0);
        else
        {
            if(num2.at(answer.size() - 1) != 0)
                cout << num2.at(answer.size() - 1);
        }
        
    }
    cout << " = ";
    for(int i = answer.size() - 1; i >= 0; i--){
        if(i != answer.size() - 1)
            cout << answer.at(i);
        else if(answer.size() == 1)
            cout << answer.at(0);
        else
        {
            if(answer.at(answer.size() - 1) != 0)
                cout << answer.at(answer.size() - 1);
        }
        

    }
    cout << '\n';



}
int main()
{
    while(cin >> temp){
        cout << "Original number was " << temp << '\n';
        int Chain_length = 0;
        if(temp[0] == '0')
            break;
        input();
        Chain_length++;
        cal();
        while(previous_answer != answer){
            previous_answer.clear();
            previous_answer = answer;
            num1.clear();
            num2.clear();
            for(int i = answer.size() - 1; i >= 0; i--)
                num1.push_back(answer.at(i));
            if(num1.at(num1.size()-1) == 0 && num1.size() != 1)
                num1.erase(num1.end());
            answer.clear();
            cal();
            Chain_length++;
    }
        cout << "Chain length " << Chain_length <<"\n\n";
        
        previous_answer.clear();
        
        num1.clear();
        
        answer.clear();
        num2.clear();
    }
}