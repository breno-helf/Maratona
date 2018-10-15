#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e4 + 20;

struct query {
    int type;
    int u, v;
    
    query(int T = 0, int U = 0, int V = 0):
        type(T), u(U), v(V) {}
};


int n, k;
int p[MAX];
query Q[MAX / 4];

int dad[MAX], sz[MAX];
bool ans[MAX / 4];
int valid[MAX];

int find(int x) {
    if (dad[x] == x) return x;
    else return (dad[x] = find(dad[x]));
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;
    
    if (sz[b] > sz[a]) swap(a, b);

    dad[b] = a;
    sz[a] += sz[b];

    return 1;
}

int main() {
    int T;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);

            dad[i] = i;
            sz[i] = 1;
            valid[i] = 0;
        }
        
        
        for (int i = 1; i <= k; i++) {
            char type;
            int u, v;
            
            scanf(" %c", &type);

            if (type == 'C') {
                scanf("%d", &u);
                valid[u]++;
                v = p[u];
                
                Q[i] = query(0, u, v);
            } else {
                scanf("%d %d", &u, &v);

                Q[i] = query(1, u, v);
            }            
        }

        for (int i = 1; i <= n; i++) {
            if (valid[i] == 0) {
                int v = p[i];
                if (v != 0) unite(i, v);
            }            
        }
        
        int j = 0;
        for (int i = k; i >= 1; i--) {
            int type = Q[i].type;
            int u = Q[i].u, v = Q[i].v;
            
            if (type == 0) {
                valid[u]--;
                if (v != 0 && valid[u] == 0)
                    unite(u, v);                       
            } else {
                ans[++j] = (find(u) == find(v));
            }            
        }

        printf("Case #%d:\n", t);
        for (int i = j; i >= 1; i--) {
            if (ans[i]) puts("YES");
            else puts("NO");
        }        
    }

    return 0;    
}
