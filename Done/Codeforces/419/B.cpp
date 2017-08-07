//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k, q;
int acc[MAX];

struct event {
    int x, t;
    event(int X, int T): x(X), t(T) {}
    bool operator < (const event ot) const {
	return (x != ot.x) ? (x < ot.x) : (t < ot.t);
    }
};
vector<event> E;

int main() {
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0 ; i < n; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	E.pb(event(a, 1));
	E.pb(event(b + 1, 0));
    }
    sort(E.begin(), E.end());
    
    int cur = 0;
    int A = 0;
    for (int i = 1; i <= 200000; i++) {
	//debug("--> hi\n");
	acc[i] = acc[i - 1];
	while (cur < (int)E.size() && E[cur].x == i)
	    A += (E[cur++].t == 0 ? -1 : 1);
	if (A >= k) acc[i]++;
    }

    for (int i = 0; i < q; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", acc[b] - acc[a - 1]);
    }
    return 0;
}

