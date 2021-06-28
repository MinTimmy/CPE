//uva10530
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

int num[11];
char s1[10], s2[10];

main(){
	int n;
	int i, j, ans;
    while(scanf("%d",&n) != EOF){
    	if(n == 0) break;
        memset(num, 0, sizeof(num));
        ans = 0;
        scanf("%s%s",s1,s2);
        while(s1[0] != 'r'){
        	if(ans == 0){
            	if(s2[0] == 'h'){
			    	for(i = n; i <= 10; i++){
            			if(num[i] == -1)
                			ans = -1;
                		else
                			num[i] = 1;
        			}
				}
           		else{
                	for(i = n; i >= 1; i--){
            			if(num[i] == 1)
                			ans = -1;
                		else
                			num[i] = -1;
        			}
            	}
            }
            scanf("%d%s%s",&n,s1,s2);
        }
        if(ans == 0 && num[n] == 0)
            printf("Stan may be honest\n");
        else
            printf("Stan is dishonest\n");
    }
    return 0;
}

