# UVA 1316

## Explanation
輸入有多列。每列開頭給定一正整數 N （N ≦ 10000），代表有 N 個商品。緊接著有 N 對正整數 p 、 d （1 ≦ p 、 d ≦ 10000），每對表示一個商品的價值以及其販賣期限。

天數從第一天開始，一次只能賣一個商品，而每個商品皆只需一天即可賣出。試問，能賣出的商品總價值最大為多少？

## Solution

可以看到在 K 天內，盡量塞價值越高的越好，且每個商品本身應越接近自己的販賣期限越好（因為塞在太前面的天數可能會使得販賣期限較前面的商品擠不進去）。

因此，我們可以先將商品們按照期限由大到小排，並定義其中最大的期限天數為 M 。

因此我們從第 M 天開始跑到第 1 天，對於第 i 天，看有哪些商品的期限是這天（因為有先由大到小排序過，且天數也是由大到小，因此可以使用一個指標來快速地搜尋），就將其加入優先佇列（Priority Queue，一開始為空的）之中。該優先佇列的排序依據是商品價值越大的排越前面（上面），所以從中取出的會是價值最大的。

接著，我們對於這天就可以從中挑出價值最大的商品且盡量讓該商品盡量靠近期限，不過記得挑的時候注意優先佇列是否為空（空的當然就挑不了）。

將上面挑出的商品之價值加總即是所求。
## min_element & max_element
min_element 在array中找最大值
max_element 在array中找最小值
```
    #include <algorithm>
    int myints[] = {3,7,2,5,6,4,9};
    std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';
    std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';
```

## memset 
```
    #include <string.h>
    int n[100];
    memset(n, 0,sizeof(n)); // 0可以用
    memset(n, -1,sizeof(n)); // -1可以用
    memset(n, 10,sizeof(n)); // 其餘的數字都不可以用
```


## accumulate
find sum of array
```
    #include <iostream>
    #include <numeric>
    using namespace std;
    int main (){
    int arr[] = { 2, 5, 7, 8, 2, 6, 9 };
    int n = 7, sum = 0;
    sum = accumulate(arr, arr+n, sum);
    cout<<"The array sum is "<<sum;
    return 0;
}

``
