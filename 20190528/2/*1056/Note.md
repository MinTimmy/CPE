# UVA 1056 
## Explanation
    現在有多個人，任意兩個人可能有直接關係，或是沒有直接關係
    依序輸入兩個人的名字，代表這兩個人是有直接關係的
    要求輸出最大有幾度分隔(maximum degree of separation)(任意選兩個人，他們的間隔一定會不大於輸出的答案)
    若是可以找到兩個人中間沒有間隔(就是沒有間接關係)，輸出”DISCONNECTED”
    
## Solution
    這是一題 All-Pairs Shortest Path 的題目
    使用 Floyd-Warshall 演算法來解題
    Floyd-Warshall 演算法

當要從點 i 走到點 j 時，要不就是從 i 走到 j， i → j ，要不就是經過一個點 k， i → k → j
這個演算法主要是用三層迴圈實作


## std::distance
Calculates the number of elements between first and last.
```
// advance example
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <list>         // std::list

int main () {
  std::list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10);

  std::list<int>::iterator first = mylist.begin();
  std::list<int>::iterator last = mylist.end();

  std::cout << "The distance is: " << std::distance(first,last) << '\n';

  return 0;
}
```
Output: The distance is: 10

