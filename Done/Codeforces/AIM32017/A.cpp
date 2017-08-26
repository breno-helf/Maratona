//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
int k;
int cnt[MAX];
int main() {
    cin >> s >> k;
    int n = s.size();
    for (char c : s) cnt[c]++;
    if (n < k) cout << "impossible\n";
    else {
	int q = 0;
	for (char c = 'a'; c <= 'z'; c++) if (cnt[c]) q++;
	if (q >= k) cout << 0 << '\n';
	else cout << k - q << '\n';
    }
    return 0;
}

