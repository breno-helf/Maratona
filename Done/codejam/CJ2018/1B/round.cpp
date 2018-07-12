#include <bits/stdc++.h>
using namespace std;

const int MAX = 512;

typedef pair<int, int> pii;

int n, l;
int C[MAX];
int DP[MAX][MAX];

double calc(int x, int y) {
    double A = ((double)100.0 * x / (double)y) - (double)(100 * x / y);
    return A;
}

int round(int x, int y) {
    double A = calc(x, y);

    if (A < .5) return (100 * x) / y;

    return (100 * x + y - 1) / y;
}

int solve(int i, int r) {
    if (i == 0) return 0;

    int &res = DP[i][r];
    if (res != -1) return res;
    
    for (int j = 0; j <= r; j++) {
        res = max(res, solve(i - 1, r - j) + round(C[i] + j, n));
    }

    return res;
}


int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &n, &l);
        int sum = 0;
        memset(DP, -1, sizeof(DP));
        memset(C, 0, sizeof(C));
        
        for (int i = 1; i <= l; i++) {
            scanf("%d", &C[i]);

            sum += C[i];
        }

        int r = n - sum;
        int ans = solve(2 * n, r);
        
        printf("Case #%d: ", t);
        printf("%d\n", ans);
    }
    
    return 0;
}
