// tolower example (C++)
#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::tolower
#include<bits/stdc++.h>

using namespace std;

int main ()
{
//   std::locale loc;
  std::string su="Test String.\n";
//   for (std::string::size_type i=0; i<str.length(); ++i)
//     std::cout << std::tolower(str[i],loc);
    transform(su.begin(), su.end(), su.begin(), ::toupper);
    cout << su;
  return 0;
}