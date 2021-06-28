//uva11678
#include <iostream>
using namespace std;

int main() {
	int m, n;
	while ((cin >> m >> n)){
		if (m == 0 && n == 0)
			break;
		int a[m], b[n], an = 0, bn = 0;
		for (int i = 0;i < m; i++){
			cin >> a[i];
			if (i > 0 && a[i] == a[i - 1])
				a[i - 1] = 0;
		}
		for (int i = 0;i < n; i++){
			cin >> b[i];
			if (i > 0 && b[i] == b[i - 1])
				b[i - 1] = 0;
		}

		for (int i = 0, j = 0;i < m && j < n;){
			if (a[i] == b[j]){
				a[i] = 0;
				b[j] = 0;
				i++;
				j++;
			}
			else{
				if(a[i] < b[j])
					i++;
				else
					j++;
			}
		}
		for (int i = 0;i < m; i++)
			if (a[i] > 0)
				an++;
		for (int i = 0;i < n; i++)
			if (b[i] > 0)
				bn++;
		cout << ((an > bn)?bn : an) << endl;
	}
	return 0;
}

