//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
int g[MAX][MAX];
int qtd[MAX][MAX];

bool valid(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= n);
}

void sum(int x, int y, int t) {
    if (t == 0) {
        for (int i = x; i < x + k; i++) {
            qtd[i][y]++;
        }
    } else {
        for (int j = y; j < y + k; j++) {
            qtd[x][j]++;
        }
    }
}

void boat(int x, int y, int t) {
    bool ok = true;
    if (t == 0) {
        if (!valid(x + k - 1, y)) ok = false;
        else {
            for (int i = x; i < x + k; i++)
                if (g[i][y] == 1) ok = false;
        }
    } else {
        if (!valid(x, y + k - 1)) ok = false;
        else {
            for (int j = y; j < y + k; j++)
                if (g[x][j] == 1) ok = false;
        }
    }

    if (ok) sum(x, y, t);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            scanf(" %c", &c);
            g[i][j] = (c == '#' ? 1 : 0);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            boat(i, j, 0);
            boat(i, j, 1);
        }
    }

    int mx = -1;
    int I, J;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (qtd[i][j] > mx) {
                mx = qtd[i][j];
                I = i;
                J = j;
            }
        }
    }

    printf("%d %d\n", I, J);
    return 0;
}
