//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

ll ini, fim, t;
ll ans;
ll esp;
ll a[MAX], b[MAX];

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    cin >> ini >> fim >> t;
    
    cin >> n;
    ll last = ini;

    for (int i = 0; i < n; i++) {
	cin >> a[i];
	if (a[i] < last) {
	    b[i] = last + t;
	    last = b[i];
	} else {
	    b[i] = a[i] + t;
	    last = b[i];
	}
    }

    ans = ini;
    esp = (ll)(1e15);
    a[n] = fim;
    
    for (int i = 0; i < n; i++) {
	ll cur = a[i] - 1, st = b[i] - t;
	if ((st - cur) < esp && (st + t <= fim)) {
	    esp = st - cur;
	    ans = cur;
	}
	cur = b[i];
	if (cur < a[i + 1] && (cur + t <= fim)) {
	    esp = 0;
	    ans = cur;
	}
    }
    
    cout << ans << '\n';

}

