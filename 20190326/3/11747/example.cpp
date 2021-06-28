//uva11747
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MST[1000];

int find(int x){
    if (x == MST[x])
        return x;
    else {
        MST[x] = find(MST[x]);
        return MST[x];
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m)) {
        if (!m && !n)
            break;

        int u[30000];
        int v[30000];
        int edge[30000];
        vector<int> Edge;
        vector<int> heav;

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u[i], &v[i], &edge[i]);
            Edge.push_back(edge[i]);
        }

        sort(edge, edge+m);
        for (int i = 0; i < n; i++)
            MST[i] = i;

        for (int i = 0; i < m; i++) {
            vector<int>::iterator itr = find(Edge.begin(), Edge.end(), edge[i]);
            int index = distance(Edge.begin(), itr);
            if (find(u[index]) != find(v[index]))
                MST[find(u[index])] = find(v[index]);

            else
                heav.push_back(edge[i]);
        }

        if (heav.empty())
            printf("forest\n");
        else {
            printf("%d", heav[0]);
            for (int i = 1; i < heav.size(); i++)
                printf(" %d",heav[i]);
            printf("\n");
        }
    }

    return 0;
}


