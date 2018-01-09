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

int n, m;
vector<int> adj[MAX];
int mrk[MAX];
int l[MAX], r[MAX];

void dfs(int u) {
    //debug("Visitando %d\n", u);
    mrk[u] = 1;
    
    for (int v : adj[u]) {
	if (!mrk[v]) dfs(v);
    }
}

int main() {
    cin >> n >> m;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
	cin >> l[i] >> r[i];
	for (int j = l[i] + 1; j <= r[i]; j++) {
	    adj[l[i]].pb(j);
	}
    }

    dfs(0);
    
    if (mrk[m]) {
	cout << "YES\n";
    } else cout << "NO\n";
}


