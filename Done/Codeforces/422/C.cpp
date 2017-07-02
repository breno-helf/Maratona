//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, x;

struct voucher {
    int l, r, c;

    voucher (int L, int R, int C): l(L), r(R), c(C) {}

    voucher (): l(0), r(0), c(0) {}

    bool operator < (voucher ot) const{
	return l < ot.l;
    }

    int duration () {
	return r - l + 1;
    }
};

vector < voucher > v;

vector < voucher > d[MAX];

int main () {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
	int a, b, c;
	cin >> a >> b >> c;
	v.pb(voucher(a, b, c));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
	d[v[i].duration()].pb(v[i]);
    }
    
    
    int resp = 2e9 + 1;
    
    for (int i = 0; i < n; i++) {
	voucher C = voucher(v[i].r, 0, 0);
	int h = x - v[i].duration();
	if (h < 0) continue;
	int j = (int)(upper_bound(d[h].begin(), d[h].end(), C) - d[h].begin());
	
	for (; j < (int)d[h].size(); j++) {
	    resp = min(resp, v[i].c + d[h][j].c);
	}
    }

    if (resp == 2e9 + 1) resp = -1;
    
    cout << resp << '\n';
}
