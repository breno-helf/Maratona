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

ll a[MAX], b[MAX], dp[MAX];
int n;

double intersect (pll l, pll r) {
    return ((double)(r.second - l.second))/((double)(l.first - r.first));
}

bool test (pll l, pll r, ll x) {
    return (l.first * x + l.second) > (r.first * x + r.second);
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
	cin >> a[i];
    for (int i = 1; i <= n; i++)
	cin >> b[i];
    dp[1] = 0;
    vector<pll> st;
    int cur = 0;
    st.pb(mp(b[1], 0));
    for (int i = 2; i <= n; i++) {
	if (cur >= (int)st.size()) cur = st.size() - 1;
	while (cur < ((int)st.size() - 1) && test(st[cur], st[cur + 1], a[i]))
	    cur++;
	dp[i] = st[cur].first * a[i] + st[cur].second;
	pll line = mp(b[i], dp[i]);
	while (st.size() >= 2 && (intersect(st[st.size() - 2], line) <= intersect(st[st.size() - 1], st[st.size() - 2]))) {
	    st.pop_back();
	}
	st.pb(line);	
    }
    cout << dp[n] << '\n';
}
