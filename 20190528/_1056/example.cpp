//uva1056
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
#define MAX 999999

int main() {

	int m, n, t = 1;
	while ((cin >> m >> n)) {
		if(m ==0 || n == 0)
			break;
		map<string, int> people;
		int arr[m][m];
		for(int i = 0; i < m; i++)
			for(int j= 0; j < m; j++)
				arr[i][j] = MAX;
		int ct = 0;
		for (int i = 0; i < n; i++){
			string s1, s2;
			cin >> s1 >> s2;
			if(people.find(s1) == people.end()) {
				people[s1] = ct;
				ct++;
			}
			if(people.find(s2) == people.end()) {
				people[s2] = ct;
				ct++;
			}
			arr[people.find(s1)->second][people.find(s2)->second] = arr[people.find(s2)->second][people.find(s1)->second] = 1;
		}
		int ans = 0;
		for (int k = 0; k < m; k++)
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
					if (arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < m; j++)
				if (ans < arr[i][j])
					ans = arr[i][j];
		cout << "Network " << t++ << ": " << ((ans < MAX)?to_string(ans):"DISCONNECTED") << endl << endl;
	}
	return 0;
}