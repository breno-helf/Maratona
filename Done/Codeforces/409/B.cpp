//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s, t;
string resp;
int n;

int main() {
    cin >> s >> t;
    n = s.size();
    bool ok = true;
    for (int i = 0; i < n; i++) {
	if (s[i] < t[i]) ok = false;
	else resp += t[i];
    }
    if (!ok) cout << -1 << '\n';
    else cout << resp << '\n';
}

