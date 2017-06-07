//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 90;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int dp[MAX][MAX][MAX][3];
int n;
char s[MAX];
vector<int> pos[3];

int cost (int V, int K, int O, int id) {
    int v[MAX];
    memset(v, 0, sizeof(v));
    for (int i = 0; i < V; i++) v[pos[0][i]] = 1;
    for (int i = 0; i < K; i++) v[pos[1][i]] = 1;
    for (int i = 0; i < O; i++) v[pos[2][i]] = 1;
    int ret = 0;
    for (int i = id - 1; i >= 0; i--) {
	if (v[i] == 0) ret++;
    }
    return ret;
}


int solve (int V, int K, int O, int last) {
    int cur = V + K + O;
    if (cur == n) return 0;
    int &res = dp[V][K][O][last];
    if (res != -1) return res;
    
    res = INF;
    vector<int> test;
    
    test.pb(0); test.pb(2); test.pb(1);
    if (last == 0) test.pop_back();
    
    for (int T : test) {
	if (T == 0) {
	    if ((int)pos[0].size() == V) continue;
	    res = min (res, solve (V + 1, K, O, 0) + cost (V, K, O, pos[0][V])); 
	} else if (T == 1) {
	    if ((int)pos[1].size() == K) continue;
	    res = min (res, solve (V, K + 1, O, 1) + cost (V, K, O, pos[1][K]));
	} else {
	    if ((int)pos[2].size() == O) continue;
	    res = min (res, solve (V, K, O + 1, 2) + cost (V, K, O, pos[2][O]));
	}
    }
    
    return res;
}


int main () {
    scanf ("%d", &n);
    scanf (" %s", s);
    for (int i = 0; i < n; i++) {
	if (s[i] == 'V') pos[0].pb(i);
	else if (s[i] == 'K') pos[1].pb(i);
	else pos[2].pb(i);
    }
    memset(dp, -1, sizeof(dp));
    int resp = INF;
    resp = min(resp, solve(0, 0, 0, 2));
    
    printf ("%d\n", resp);

    return 0;
}

