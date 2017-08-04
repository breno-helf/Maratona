//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int k, n;
ll a[MAX], b[MAX];
ll acc[MAX];
set<int> can;
map<int, bool> resp;
int ans = 0;

bool test(int num) {
    if (resp.find(num) != resp.end()) return false;
        
    for (int i = 1; i <= n; i++)
	if (can.find(b[i] - num) == can.end()) {
	    return resp[num] = false;	    
	}
    return resp[num] = true;
}


void solve() {
    for (int j = 1; j <= n; j++) {
	for (int i = 1; i <= k - n + 1; i++) {
	    int num = b[j] - acc[i];
	    if (test(num)) ans++;
	}
    }
}

int main() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= k; i++) {
	scanf("%lld", a + i);
	acc[i] = acc[i - 1];
	acc[i] += a[i];
	can.insert(acc[i]);
    }

    for (int i = 1; i <= n; i++) {
	scanf("%lld", b + i);
    }
    
    solve();
    
    printf("%d\n", ans);
}
