//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 312345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
ll k;
pll c[MAX];
ll t[2 * MAX];
set<int> pos;
ll resp[MAX];
ll tot;

int main() {
    scanf("%d%lld", &n, &k);

    for (int i = k + 1; i < 2 * MAX; i++) {
	pos.insert(i);
    } 
    
    for (int i = 1; i <= n; i++) {
	ll cost;
	scanf("%lld", &cost);
	c[i] = pll(-cost, i);
    }
    sort(c + 1, c + n + 1);

    for (int i = 1; i <= n; i++) {
	int me = c[i].second;
	ll cost = - c[i].first;
	//printf("--> %d\n", me);
	auto it = pos.lower_bound(me);
	t[i] = *it;
	pos.erase(it);
	tot += cost * (t[i] - me);
	resp[me] = t[i];
    }

    printf("%lld\n", tot);

    for (int i = 1; i <= n; i++) {
	printf("%lld ", resp[i]);
    }
    printf("\n");
}
