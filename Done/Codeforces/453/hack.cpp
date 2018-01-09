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

vector<int> adj[MAX];
int mrk[MAX];

void dfs(int u) {
    //debug("Visitando %d\n", u);
    mrk[u] = 1;
    
    for (int v : adj[u]) {
	if (!mrk[v]) dfs(v);
    }
}

bool brelf(int n, int m, vector<int>& l, vector<int>& r) {
    int cur = 0;
    for (int i = 0; i < n; i++) { 
	for (int j = l[i] + 1; j <= r[i]; j++) { 
	    adj[l[i]].pb(j);
	}
    }

    dfs(0);
    
    if (mrk[m]) {
	return true;
    }

    return false;
}

bool pacboy002(int n, int m, vector<int>& l, vector<int>& r) {
    int s = 0;
    for (int i = 0; i < n; i++) {
	if (l[i] <= s) s = max(s, r[i]);
	else break;
    }
    if (m <= s) return true;

    return false;
}



int main() {
    bool (*hack)(int, int, vector<int>&, vector<int>&);

    hack = pacboy002;
    
    vector<pii> NM;
    vector< vector<int> > L(3);
    vector< vector<int> > R(3);
    vector<bool> ans;
    
    NM.pb(pii(3, 5));
    L[0].pb(0); R[0].pb(2);
    L[0].pb(2); R[0].pb(4);
    L[0].pb(3); R[0].pb(5);
    ans.pb(true);

    NM.pb(pii(3, 7));
    L[1].pb(0); R[1].pb(4);
    L[1].pb(2); R[1].pb(5);
    L[1].pb(6); R[1].pb(7);
    ans.pb(false);
    
    for (int i = 0; i < (int)NM.size(); i++) {
	int n = NM[i].first, m = NM[i].second;
	vector<int> l(MAX);
	vector<int> r(MAX);

	for (int k = 0; k < n; k++) {
	    l[k] = L[i][k];
	    r[k] = R[i][k];
	}
	
	assert(brelf(n, m, l, r) == ans[i]);
	assert(hack(n, m, l, r) == ans[i]);	
    }
    
}
