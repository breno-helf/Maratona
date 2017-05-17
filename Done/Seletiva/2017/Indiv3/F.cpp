//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = (4 * (1e6)) + 10;
const int N   = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

// Seg de mínimo

int n, A;
pii M[N];

struct seg {
    int num;
    int lazy;
}tree[4 * MAX];

struct event {
    int pos, ed;
    int l, r;
    
    event (int POS, int ED, int L, int R): pos(POS), ed(ED), l(L), r(R) {} 
    event (): pos(0), ed(0), l(0), r(0) {}

    bool operator < (event ot) const {
        return ot.pos > pos;
    }
};

void build (int id, int l, int r) {
    //debug (">> You called %d %d %d\n", id, l, r);
    if (l == r) {
	tree[id].num = 0;
	tree[id].lazy = 0;
	return;
    }

    int mid = (l + r) / 2;
    int esq = 2 * id;
    int dir = 2 * id + 1;

    build (esq, l, mid);
    build (dir, mid + 1, r);

    tree[id].num = max(tree[esq].num, tree[dir].num);
    tree[id].lazy = 0;    
}

void prop (int id, int l, int r) {
    if (tree[id].lazy != 0) {
	tree[id].num = max(tree[id].num, tree[id].lazy);
	if (l != r) {
	    int esq = 2 * id;
	    int dir = 2 * id + 1;
	    tree[esq].lazy = max(tree[id].lazy, tree[esq].lazy);
	    tree[dir].lazy = max(tree[id].lazy, tree[dir].lazy);
	}
	tree[id].lazy = 0;
    }    
}

void update (int id, int l, int r, int lo, int hi, int val) {
    if (l >= lo && r <= hi) {
	tree[id].lazy = max(tree[id].lazy, val);
	return;
    }
    
    prop(id, l, r);

    int mid = (l + r) / 2;
    int esq = 2 * id;
    int dir = 2 * id + 1;

    if (mid >= lo)
	update(esq, l, mid, lo, hi, val);
    if (mid < hi)
	update(dir, mid + 1, r, lo, hi, val);

    prop(esq, l, mid);
    prop(dir, mid + 1, r);

    tree[id].num = min(tree[esq].num, tree[dir].num);
}

int query (int id, int l, int r, int lo, int hi) {
    prop(id, l, r);
    
    if (l >= lo && r <= hi) return tree[id].num;
    
    int mid = (l + r) / 2;
    int esq = 2 * id;
    int dir = 2 * id + 1;
    
    int ret = INF;
    if (mid >= lo) ret = min(ret, query(esq, l, mid, lo, hi));
    if (mid < hi) ret = min(ret, query(dir, mid + 1, r, lo, hi));

    return ret;    
}

bool test (int S) {
    vector<event> E;
    int F = (2 * 1e6) - S;
    int T = (2 * 1e6) + S;

    int L = INF;
    int R = -INF;
    
    for (int i = 0; i < n; i++) {
	int x = M[i].first;
	int y = M[i].second;
	if ((x + S) < F || (x - S) > T) continue;
	if ((y + S) < F || (y - S) > T) continue;
	
	E.pb(event(x - S, x + S, y - S, y + S));
	debug ("Carinha %d intersec\n", i);
	L = min(L, y - S);
	R = max(R, y + S);
    }
    sort(E.begin(), E.end());
    debug ("%d -- %d %d\n", S, L, R);

    if (L == INF && R == -INF) return false;
    debug ("Meu quadrado é %d %d\n", F, T);
    L = min(L, F);
    R = max(R, T);
    build (1, L, R);
    update(1, L, R, F, T, F - 1);
    
    for (auto e : E) {
	int Q = query(1, L, R, max(e.l, F), min(e.r, T));
	debug ("%d *** %d\n", e.pos, Q);
	if (e.pos <= (Q + 1)) {
	    debug ("Começou quadrado em %d ate %d cm y [%d, %d]\n", e.pos, e.ed, e.l, e.r);
	    update(1, L, R, e.l, e.r, e.ed);
	}
    }
    
        debug ("-- O menor y enxergado eh %d\n\n", query(1, L, R, F, T));
    
    return query(1, L, R, F, T) >= T;     
}

vector<int> quadrante (int x, int y) {
    vector<int> ret;
    
    if (x >= 0 && y >= 0)
	ret.pb(0);
    if (x >= 0 && y <= 0)
	ret.pb(1);
    if (x <= 0 && y >= 0)
	ret.pb(2);
    if (x <= 0 && y <= 0)
	ret.pb(3);
    return ret;
}

int main () {
    int T = 1;
    
    while (true) {
	scanf ("%d", &n);
	if (n == -1) break;
	int D[] = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
	    int x, y;
	    scanf ("%d%d", &x, &y);
	    M[i] = pii(x + (2 * 1e6), y + (2 * 1e6));
	    vector<int> v = quadrante (x, y);
	    for (int j = 0; j < (int)v.size(); j++) {
		D[v[j]] = 1;
	    }
	}

	bool finish = false;
	
	for (int i = 0; i < 4; i++) {
	    if (D[i] == 0) {
		printf ("Case %d: never\n", T++);
		finish = true;
		break;
	    }
	}

	if (finish) continue;
	
	int l = 1, r = 1e6;

	while (l < r) {
	    int mid = (l + r) / 2;
	    if (test(mid)) r = mid;
	    else l = mid + 1;
	}
	
	if (test(l))
	    printf ("Case %d: %d\n", T++, l);
	else
	    printf ("Case %d: never\n", T++);	
    }
    return 0;
}
