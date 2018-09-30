#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args);

typedef long long ll;

const int MAX = 5e2 + 10;
//const int MAXS = 1e4 + 10;
const int INF = 0x3f3f3f3f;


struct app {
    int d, s, id;
    app(int D = 0, int S = 0, int ID = 0):
        d(D), s(S), id(ID) {}

    bool operator < (const app ot) const {
        return (s - d) < (ot.s - ot.d);
    }
}A[MAX];

int n, c;
int dpT[MAX][MAX];
int dpI[MAX][MAX];
int last[MAX][MAX];

int main() {
    memset(dpI, INF, sizeof(dpI));
    memset(dpT, INF, sizeof(dpT));
    memset(last, -1, sizeof(last));
    
    scanf("%d%d", &n, &c);
        
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &A[i].d, &A[i].s);
        A[i].id = i;
        //A[i].d = max(A[i].d, A[i].s);
    }

    sort(&A[1], &A[n + 1]);
    
    int best = 0;

    for (int i = 0; i <= n; i++) {
        dpI[i][0] = dpT[i][0] = 0;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            int cur = max(dpT[i - 1][k - 1], dpI[i - 1][k - 1] + max(A[i].d, A[i].s));
            dpT[i][k] = dpT[i - 1][k];
            dpI[i][k] = dpI[i - 1][k];
            last[i][k] = last[i - 1][k];
            
            if (cur < dpT[i][k]) {
                dpT[i][k] = cur;
                dpI[i][k] = dpI[i - 1][k - 1] + A[i].s;
                last[i][k] = i;
            }
        }

        if (dpT[n][k] <= c) best = k;
    }
    
    vector<int> order;
    int qtd = best;
    int cur = last[n][qtd];
    while (qtd > 0) {
        order.push_back(A[cur].id);
        cur = last[cur - 1][--qtd];
    }
    reverse(order.begin(), order.end());

    printf("%d\n", best);
    
    for (int i = 0; i < best; i++) {
        printf("%d ", order[i]);
    }
    
    printf("\n");
}
