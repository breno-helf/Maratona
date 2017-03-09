#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k, a[MAX], b[MAX];
int mrk[MAX];
pii f[MAX];

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	f[i].second = i;
    }
    for (int i = 0; i < n; i++) {
	cin >> b[i];
	f[i].first = a[i] - b[i];
    }
    sort(f, f + n);
    ll resp = 0;
    for (int i = 0; i < k; i++) {
	debug("--> %d\n", f[i].second);
	mrk[f[i].second] = 1;
	resp += a[f[i].second];
    }
    for (int i = 0; i < n; i++) {
	if (mrk[i] == 0) resp += min(b[i], a[i]);
    }
    cout << resp << '\n';
}
