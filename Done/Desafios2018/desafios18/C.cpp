#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3 + 10;
const int MAXM = 1e6 + 10;

int P[MAX];
int R[MAXM];

int main() {
    freopen("H.in", "r", stdin); 
    
    for (int i = 1; i <= 100; i++) {
        P[i] = i * i;
        R[i * i] = i;
    }

    int n, m;

    scanf("%d %d", &m, &n);

    int ans = 0;
    
    for (int j = 2; j <= n; j++) {
        ans += 1;
        for (int x = 1; x <= m; x++) {
            ans += 1;
            if (j > 2) continue;
            for (int y = x; y <= m; y++) {
                int X = P[x], Y = P[y];
                if (X + Y >= MAXM) continue;

                
                int z = R[X + Y];

                //printf("%d %d %d -- %d %d %d\n", x, y, z, X, Y, X + Y); 

                if (z >= y && z <= m) ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
