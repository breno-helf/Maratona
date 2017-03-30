#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int pai[MAX], sz[MAX];
vector<int> cmp[MAX];
int dp[MAX][MAX];
int n, m, S;
int w[MAX], b[MAX];
int Cw[MAX], Cb[MAX];
int num;
map<int, int> ID;

int find (int a) {
    if (a == pai[a]) return a;
    return pai[a] = find(pai[a]);
}

void une (int a, int c) {
    a = find(a);
    c = find(c);
    if (a == c) return;

    if (sz[a] < sz[c]) swap(a, c);
    pai[c] = a;
    sz[a] += sz[c];
}

int solve (int i, int s) {
    if (s < 0) return -INF;
    if (i == num) return 0;
    if (s == 0) return 0;
    int &res = dp[i][s];

    if (res != -1) return res;
    int cur = 0;
    cur = max(cur, solve(i + 1, s));
    cur = max(cur, solve(i + 1, s - Cw[i]) + Cb[i]);
    for (int e : cmp[i]) {
	cur = max(cur, solve(i + 1, s - w[e]) + b[e]);
    }
    return res = cur;
}

int main () {
    for (int i = 1; i < MAX; i++) {
	sz[i] = 1;
	pai[i] = i;
    }
    memset(dp, -1, sizeof(dp));
    
    scanf ("%d%d%d", &n, &m, &S);
    
    for (int i = 1; i <= n; i++)
	scanf("%d", w + i);
    for (int i = 1; i <= n; i++)
	scanf("%d", b + i);


    for (int i = 0; i < m; i++) {
	int u, v;
	scanf ("%d%d", &u, &v);
	une(u, v);
    }
    num = 1;

    for (int i = 1; i <= n; i++) {
	if (ID[find(i)] == 0) {
	    ID[find(i)] = num++;
	}
	cmp[ID[find(i)]].pb(i);
    }
    
    for (int i = 1; i < num; i++) {
	for (int e : cmp[i]) {
	    Cw[i] += w[e];
	    Cb[i] += b[e];
	}	
    }
    int resp = solve(1, S);
    printf("%d\n", resp);
    return 0;
}

