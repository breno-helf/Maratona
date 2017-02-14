//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, m;
ll dist[MAX][3];
string s[MAX];
ll resp;

bool small (char c) {
    return (c >= 'a' && c <= 'z');
}

bool spec (char c) {
    return (c == '#' || c == '*' || c == '&');
}

bool dig (char c) {
    return (c >= '0' && c <= '9');
}

int main () {
    for (int i = 0; i < MAX; i++) {
	for (int k = 0; k < 3; k++)
	    dist[i][k] = 100 * 100 *50;
    }
    resp = 100 * 100 * 50;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
	cin >> s[i];
	
	for (ll k = 0; k < m; k++) {
	    if (small(s[i][k]))
		dist[i][0] = min(dist[i][0], k);

	    else if (dig(s[i][k]))
		dist[i][1] = min(dist[i][1], k);

	    else if (spec(s[i][k]))
		dist[i][2] = min(dist[i][2], k);	    
	}
	for (ll k = m - 1; k > 0; k--) {
	    if (small(s[i][k]))
		dist[i][0] = min(dist[i][0], m - k);
	    
	    else if (dig(s[i][k]))
		dist[i][1] = min(dist[i][1], m - k);

	    else if (spec(s[i][k]))
		dist[i][2] = min(dist[i][2], m - k);	    
	}
	debug ("--> %lld %lld %lld\n", dist[i][0], dist[i][1], dist[i][2]);
    }

    for (ll i = 0; i < n; i++) {
	for (ll j = 0; j < n; j++) { 
	    if (j == i) continue;
	    for (ll k = 0; k < n; k++) {
		if (k == j || k == i) continue;
		resp = min(resp, dist[i][0] + dist[j][1] + dist[k][2]);
	    }
	}
    }
    cout << resp << '\n';
}

