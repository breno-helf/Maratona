//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 22;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
ll v[MAX];
int sig[MAX];

ll calc(int bm) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
	if ((1<<i)&bm) sum -= v[i];
	else sum += v[i];
    }
    return sum;
}

int dif(int bm) {
    int ret = 0;
    for (int i = 0; i < 20; i++) {
	int s = ((1<<i)&bm) ? 1 : 0;
	if (s != sig[i]) ret++;
    }
    return ret;
}

int main() {
    cin >> n;
    sig[0] = 0;
    cin >> v[0];
    for (int i = 1; i < n; i++) {
	char c;
	cin >> c >> v[i];
	if (c == '-') sig[i] = 1;
    }
    
    int resp = INF;
    
    for (int bm = 0; bm < (1<<n); bm++) {
	if (1 & bm) continue;
	
	ll sum = calc(bm);
	if (sum != 0LL) continue;
 	int DIF = dif(bm);
	resp = min(resp, DIF);
    }

    if (resp == INF) cout << -1 << endl;
    else cout << resp << endl;

    return 0;
}



