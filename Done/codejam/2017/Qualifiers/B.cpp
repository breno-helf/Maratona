//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

// 99999999999999999
// 099999999999999999

int main () {
    int t;
    ll n;
    cin >> t;
    for (int T = 1; T <= t; T++) {
	string resp;
	bool ok = false;
	cin >> n;
	resp = to_string(n);
	int tam = resp.size();
	for (int i = (tam - 1); i >= 2; i--) {
	    if (resp[i] < resp[i - 1]) {
		resp[i] = '9';
		resp[i - 1]--;
	    }
	}
	if (tam >= 2) {
	    if (resp[1] < resp[0]) {
		for (int i = 1; i < tam; i++) resp[i] = '9';
		resp[0]--;
	    }
	}
	n = stoll(resp);
	cout << "Case #" << T << ": " << n << '\n';
    }
    return 0;
}

