//This code was made by Breno Moura, Codeforces Handle: Brelf
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

const int MAX = 2123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s, t, u;

int k, z[MAX], zr[MAX];

void z_function (string a, int v[]) {
    int l, r;
    l = r = 0;
    for (int i = 1; i < (int)a.size(); i++) {
	if (i <= r)
	    v[i] = min(v[i - l], r - i + 1);
	
	while((v[i] + i) < (int)a.size() && a[v[i] + i] == a[v[i]])
	    v[i]++;
	
	if (r < (i + v[i] - 1)) {
	    l = i;
	    r = i + v[i] - 1;
	}
    }
}

int main () {
    cin >> t >> s >> k;

    u = s + '#' + t;

    z_function(u, z);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    u = s + '#' + t;

    z_function(u, zr);

    reverse(zr + s.size() + 1, zr + u.size());

    vector<int> ans;


    
    for (int i = (int)s.size() + 1; i < (int)(u.size() - s.size() + 1); i++) {
	if (((int)s.size() - (z[i] + zr[i + (int)s.size() - 1])) <= k) {
	    //	    debug("-- %d %d\n", z[i], zr[i + s.size() - 1]);
	    ans.pb(i - (int)s.size());
	}
    }

    cout << ans.size() << '\n';

    for (auto e : ans)
	cout << e << ' ';
    cout << '\n';
}
