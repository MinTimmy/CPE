//uva11220
#include<iostream>
#include<cstdio>
#include<cstring>
#include <stdio.h>

using namespace std;

main(){
	int t, ca;
	int i, site, k;
	char word[1200];

	cin >> t;
	getchar();
	getchar();
	ca = 0;
	while(t--){
		cout << "Case #" << ++ca << ":" << endl;
		while (gets(word)){
			if (word[0] == '\0')
                break;
			for (i = 0, site = 1, k = 1; word[i] != '\0'; i++, k++){
				if (word[i] ==' ')
                    k = 0;
				if (k == site) {
					cout << word[i];
					k++;
					site++;
				}
			}
			cout << endl;
		}
		if (t)
            cout << endl;
	}
	return 0;
}