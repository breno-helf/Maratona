//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
int k;

int main () {
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
	cin >> s >> k;
	int tam = s.size();
	int resp = 0;
	bool ok = true;
	for (int i = 0; i <= (tam - k); i++) {
	    if (s[i] == '-') {
		resp++;
		for (int j = i; j < (i + k); j++)
		    s[j] = (s[j] == '-') ? '+' : '-';
	    }
	}
	for (int i = 0; i < tam; i++) if (s[i] == '-') ok = false;

	cout << "Case #" << T << ": ";
	if (ok) cout << resp << '\n';
	else cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}

