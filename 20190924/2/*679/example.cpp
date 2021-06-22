//uva679
/*
樹的任何一個點第一次走左邊，第二次走右邊 
*/
#include <iostream>

using namespace std;

int main()
{
    int n; // 總共有幾筆測資
    int D; // 樹的總深度
    int I; // 要進去樹幾次

    while (cin >> n && n!=-1) {
        while(n--) {
            cin >> D >> I; // 輸入測資
            int root = 1;
            for(int i = 1; i <= D; i++)
            {
                // 如果 I 是偶數，就往右走
                if((I % 2) == 0){ 
                    root = 2 * root + 1; // 往右走，二元完全數編號有規則性 
                    I = I / 2; // 到下一個點當成 root ，調整新的 I 值 
                }
                // 如果 I 是基數，就往左走
                else{ 
                    root = 2 * root; // 往左走，二元完全數編號有規則性 
                    I = (I + 1) / 2; // 到下一個點當成 root ，調整新的 I 值 
                }
            }
            cout << root / 2 << endl;
        }
    }
    return 0;
}