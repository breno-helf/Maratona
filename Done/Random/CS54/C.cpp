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

int n, k;
int a[MAX];
int seg[4 * MAX];

void build(int id, int l, int r) {
    if (l == r) {
	seg[id] = a[l];
	return;
    }

    int esq, dir, mid;
    esq = 2 * id;
    dir = 2 * id + 1;
    mid = (l + r) / 2;

    build(esq, l, mid);
    build(dir, mid + 1, r);

    seg[id] = min(seg[esq], seg[dir]);
}

int query(int id, int l, int r, int lo, int hi) {
    if (l > hi || r < lo) return INF;
    if (l >= lo && r <= hi) return seg[id];
    
    int esq, dir, mid;
    esq = 2 * id;
    dir = 2 * id + 1;
    mid = (l + r) / 2;

    int E = query(esq, l, mid, lo, hi);
    int D = query(dir, mid + 1, r, lo, hi);

    return min(E, D);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    int pos = -1;
    for (int i = 1; i <= n; i++) {
	int Q = query(1, 1, n, i, min(i + k, n));
	if (Q < a[i]) {
	    pos = i;
	    break;
	}
    }

    if (pos != -1) {
	int p = -1, m = INF;
	for (int i = pos; i <= min(n, pos + k); i++) {
	    if (a[i] <= m) {
		m = a[i];
		p  = i;
	    }
	}

	swap(a[pos], a[p]);	     
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}
