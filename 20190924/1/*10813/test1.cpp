#include <iostream>

using namespace std;

int main()
{
   int a[] = {0,1,1,6,5,6,2};
   cout << &a[2] - &a[0]; 
}