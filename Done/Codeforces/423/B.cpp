#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

char c[MAX][MAX];
int g[MAX][MAX];
int dp[MAX][MAX];
int b;
int n, m;

int solve(int i, int j) {
    if (i < 0 || j < 0) return 0;
    
    int &res = dp[i][j];
    if (res != -1) return res;

    if (i == 0) {
	if (j == 0) res = g[i][j];
	else res = solve(i, j - 1) + g[i][j];
    } else if (j == 0) res = solve(i - 1, j) + g[i][j];

    else res = solve(i - 1, j) + solve(i, j - 1) - solve(i - 1, j - 1) + g[i][j];
    
    return res;
}

bool test(int sz) {
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (i + sz > n || j + sz > m) continue;
	    int sum = solve(i + sz - 1, j + sz - 1) - solve(i + sz - 1, j - 1) - solve(i - 1, j + sz - 1) + solve(i - 1, j - 1);
	    if (sum == b) return true;
	}
    }
    return false;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf(" %s", c[i]);
    b = 0;

    int resp = INF;
    
    for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	    if (c[i][j] == 'B') g[i][j] = 1, b++;

    if (b == 0) {
	printf("%d\n", 1);
	return 0;
    }

    int l = 0, r = min(n, m);

    while (l < r) {
	int mid = (l + r) / 2;
	if (test(mid)) r = mid;
	else l = mid + 1;
    }
    if (test(r) == false) resp = -1;
    else resp = r * r - b;
    printf("%d\n", resp);
      
    return 0;
}


