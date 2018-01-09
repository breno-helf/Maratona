//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int p[MAX], n;
vector<int> adj[MAX];

int dfs(int u) {
    int tam = 0;
    int ret = 0;
    
    for (auto v : adj[u]) {
	tam += ((int)adj[v].size() == 0) ? 1 : 0;
	ret |= dfs(v);
    }

    return (ret | !((int)adj[u].size() == 0 || tam >= 3));
}

int main() {
    cin >> n;

    for (int i = 2; i <= n; i++) {
	cin >> p[i];
	adj[p[i]].pb(i);
    }

    if (dfs(1) == 0) {
	cout << "Yes" << '\n';
    } else cout << "No" << '\n';
}


