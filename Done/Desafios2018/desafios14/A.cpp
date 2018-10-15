#include<bits/stdc++.h>
using namespace std;

const int MAX = 22;
const int TMP = 3600;

int n, t;
int b[MAX];
int dist[TMP + 10];

int main() {
    int c;

    scanf("%d", &c);

    while (c--) {
    
        scanf("%d %d", &n, &t);

        for (int i = 0; i < n; i++)
            scanf("%d", b + i);

    
        memset(dist, -1, sizeof(dist));
    
        dist[0] = 0;

        queue<int> Q;
        Q.push(0);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            //printf("--> %d %d\n", u, dist[u]); 
            
            for (int i = 0; i < n; i++) {
                int v = u + b[i];

                v = max(v, 0);
                v = min(v, TMP);
            
                if (dist[v] == -1 || (dist[u] + 1 < dist[v])) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }                
            }
        }
    
        if (dist[t] != -1) printf("%d %d\n", dist[t], 0);

        else {
            int T = t;
            while (dist[T] == -1) T++;

            printf("%d %d\n", dist[T], T - t);
        }

    }


    return 0;
}
