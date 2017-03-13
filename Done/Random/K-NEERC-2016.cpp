//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<int> adj[MAX];
int out[MAX], cur;
int n, m;

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
	int u, v;
	cin >> u >> v;
	adj[v].pb(u);
	out[u]++;
    }
    cur = 1;
    vector<int> resp;
    set<int> S;
    for (int i = 1; i <= n; i++) {
	if (out[i] == 0) S.insert(-i);
    }
    while (!S.empty()) {
	int u = -*S.begin();
	resp.pb(u);
	S.erase(S.begin());
	for (auto v : adj[u]) {
	    out[v]--;
	    if(!out[v]) S.insert(-v);
	}
    }
    reverse(resp.begin(), resp.end());
    for (int r : resp) cout << r << ' ';
    cout << '\n';
}

