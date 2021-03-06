#include <iostream>
#include <string>

using namespace std;

int main()
{
    char a[2];
    string s;
    s = "12";
    cin >> a;
    a[0] = '0';
    a[0] = s.at(0);
    cout << a;
}