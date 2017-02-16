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

const int MAX = 55;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX];
bool resp;
vector<int> v;
set<int> s;
int main () {
    resp = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	s.insert(a[i]);
    }
    for (int e : s)
	v.pb(e);
    n = v.size();
    for (int i = 0; (i + 2) < n; i++) {
	int dif = max(v[i + 1] - v[i], v[i + 2] - v[i + 1]);
	dif = max(dif, v[i + 2] - v[i]);
	debug("%d <-- \n", dif);
	if (dif < 3) resp = true;
    }
    if (resp)
	cout << "YES\n";
    else
	cout << "NO\n";
    return 0;
}

