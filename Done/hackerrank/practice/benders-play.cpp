//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
int q, k[MAX], mex[MAX], ind[MAX], out[MAX];
vector<int> adj[MAX];

bool cmp (int a, int b) {
    return (mex[a] < mex[b]);
}

void dfs (int u) {
    for (int v : adj[u]) {
	if (mex[v] == -1)
	    dfs(v);
    }
    sort(adj[u].begin(), adj[u].end(), cmp);
    mex[u] = 0;
    for (int v : adj[u])
	if (mex[u] == mex[v])
	    mex[u]++;
}


int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(mex, -1, sizeof(mex));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
	int u, v;
	cin >> u >> v;
	adj[u].pb(v);
	ind[v]++;
	out[u]++;
    }
    for (int i = 1; i <= n; i++)
	if (out[i] == 0) mex[i] = 0;
    for (int i = 1; i <= n; i++)
	if (mex[i] == -1) dfs(i);
    
    cin >> q;

    for (int i = 0; i < q; i++) {
	int tam, XOR = 0;
	cin >> tam;
	
	for (int j = 0; j < tam; j++) {
	    cin >> k[j];
	    XOR ^= mex[k[j]];
	}
	if (XOR != 0)
	    cout << "Bumi" << '\n';
	else
	    cout << "Iroh" << '\n';
    }
}

