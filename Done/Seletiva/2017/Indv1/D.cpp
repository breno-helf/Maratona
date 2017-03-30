//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2 * 711234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct node {
    int t;
    bool birth;
    int drag;
    node(int a, bool b, int c): t(a), birth(b), drag(c) {}
    node(): t(0), birth(false), drag(0) {}
    bool operator < (const node q) const {
	if (t != q.t) return t < q.t;
	if (birth != q.birth) return birth;
	return drag < q.drag;
    }
};

int gen[MAX], ans[MAX], pai[MAX];
vector<node> M;
vector<int> adj[MAX];
vector<int> pre;
int sub[MAX], pos[MAX];

struct tree {
    int mx;
} seg[MAX];

void update (int id, int l, int r, int p, int val) {
    if (l == r) {
	seg[id].mx = max(seg[id].mx, val);
	return;
    }
    int mid = (l + r) / 2;
    int esq = 2 * id, dir = 2 * id + 1;
    if (mid >= p) update(esq, l, mid, p, val);
    if (mid < p) update(dir, mid + 1, r, p, val);
    seg[id].mx = max(seg[esq].mx, seg[dir].mx);
}

int query (int id, int l, int r, int lo, int hi) {
    if (l >= lo && r <= hi) {
	return seg[id].mx;
    }
    int mid = (l + r) / 2;
    int esq = 2 * id, dir = 2 * id + 1;
    int ret = 0;
    if (mid >= lo) ret = max(ret, query(esq, l, mid, lo, hi));
    if (mid < hi) ret = max(ret, query(dir, mid + 1, r, lo, hi));
    return ret;
}

void dfs (int u) {
    pos[u] = pre.size();
    pre.pb(u);
    for (int v : adj[u])
	dfs(v);
    sub[u] = pre.size();
}

int main () {
    int t;
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {
	int n;
	scanf("%d", &n);
	memset(ans, 0, sizeof(ans));
	memset(gen, 0, sizeof(gen));
	memset(seg, 0, sizeof(seg));
	memset(pos, 0, sizeof(pos));
	memset(sub, 0, sizeof(sub));
	memset(pai, 0, sizeof(pai));
	pre.clear();
	M.clear();
	for (int i = 1; i <= n; i++) {
	    int p, ini, fim;
	    scanf("%d%d%d", &p, &ini, &fim);
	    pai[i] = p + 1;
	    adj[p + 1].pb(i);
	    if (p == -1) gen[i] = 0;
	    else gen[i] = gen[p + 1] + 1;
	    M.pb(node(ini, true, i));
	    M.pb(node(fim, false, i));
	}
	dfs(1);
	sort(M.begin(), M.end());
	for (auto e : M) {
	    int birth = e.birth;
	    int u = e.drag;
	    debug("%d -- %d %s\n", e.t, u, !birth ? "Death" : "Birth");
	    if (birth) update(1, 1, n, pos[u] + 1, gen[u]);
	    else {
		ans[u] = max(ans[u], query(1, 1, n, pos[u] + 1, sub[u]) - gen[u]);
	    }
	}
	for (int i = 1; i <= n; i++) {
	    printf("%d ", ans[i]);
	    adj[i].clear();
	}
	printf("\n");

	
    }
    return 0;
}
