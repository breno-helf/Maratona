//If you are trying to hack me I wish you can get it, Good Luck :D.
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

struct guy {
    int a, b, c;
    guy (int A, int B, int C): a(A), b(B), c(C) {}
    guy (): a(0), b(0), c(0) {}

    bool operator < (const guy ot) const {
	return a < ot.a;
    }
    bool operator == (const guy ot) const {
	return (a == ot.a);
    }
}A[MAX];

bool cmpA (guy a, guy b) {
    return a.a < b.a;
}

int n;

int seg[4 * MAX];

void build (int id, int l, int r) {
    if (l == r) {
	seg[id] = INF;
	return;
    }

    int esq = 2 * id;
    int dir = 2 * id + 1;
    int mid = (l + r) / 2;

    build (esq, l, mid);
    build (dir, mid + 1, r);

    seg[id] = min(seg[esq], seg[dir]);
}

void update (int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;

    if (l == r) {
	assert(l == pos);
	seg[id] = val;
	return;
    }
    
    int esq = 2 * id;
    int dir = 2 * id + 1;
    int mid = (l + r) / 2;
    
    if (pos <= mid) update (esq, l, mid, pos, val);
    else update (dir, mid + 1, r, pos, val);

    seg[id] = min(seg[esq], seg[dir]);
}

int query (int id, int l, int r, int lo, int hi) {
    if (hi < l || lo > r) return INF;
    if (l >= lo && r <= hi) return seg[id];

    int esq = 2 * id;
    int dir = 2 * id + 1;
    int mid = (l + r) / 2;
    
    return min(query(esq, l, mid, lo, hi), query(dir, mid + 1, r, lo, hi));
}

int main () {
    int t;
    scanf ("%d", &t);

    while (t--) {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
	    int a, b, c;
	    scanf ("%d%d%d", &a, &b, &c);

	    guy g = guy(a, b, c);
	    
	    A[i] = g;
	}

	sort(A + 1, A + n + 1, cmpA);
	
	build (1, 1, n); 
	int resp = 0;
	for (int i = 1; i <= n; i++) {
	    if (query(1, 1, n, 1, A[i].b) > A[i].c) resp++;

	    update(1, 1, n, A[i].b, A[i].c);
	}
	
	printf ("%d\n", resp);
    }
    return 0;
}
