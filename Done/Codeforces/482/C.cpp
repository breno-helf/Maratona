//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 312345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int n, X, Y;
vector<int> adj[MAX];
int sz[MAX], D;

int dfs(int u, int p) {
    sz[u] = 1;
    int val = 0;
    
    for (int v : adj[u]) {
        if (v != p) {
            if (dfs(v, u)) {
                val = 1;
                if (u == X) D = v;
            }
            sz[u] += sz[v];
        }
    }

    if (u == Y) val++;

    return val;
}

int main() {
    cin >> n >> X >> Y;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(X, 0);

    ll ans = 1LL * n * (n - 1) - 1LL * (n - sz[D]) * sz[Y];

    cout << ans << '\n';

    return 0;
}
