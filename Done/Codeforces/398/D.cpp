//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m, a[MAX];
pii c[MAX];
int k;
vector<int> resp[MAX];
set<int> pos;
map<int, int> qtd;

bool impossible () {
    int day = 0;
    for (int i = 0; i < n; i += k) {
	for (int j = 0; j < k && (i + j) < n; j++) {
	    if (a[i + j] < day)
		return true;
	}
	day++;
    }
    return false;
}

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
	scanf("%d", a + i);
	c[i] = mp(a[i], 0);
    }
    for (int i = 0; i < m; i++) {
	int b;
	scanf("%d", &b);
	c[i + n] = mp(b, i + 1);
    }
    sort(a, a + n);
    if (impossible()) {
	puts("-1");
	return 0;
    }
    sort(c, c + n + m);
    int day = 0;
    int lim = k;
    for (int i = 0; i < (n + m); i += lim) {
	debug("Day %d. ", day);
	lim = k;
	for (int j = 0; j < lim && (i + j) < (n + m); j++) {
	    int exp = c[i + j].first;
	    int tp = c[i + j].second;
	    debug ("%d ", exp);
	    if (tp == 0 && exp < day) {
		int rem = *pos.lower_bound(exp);
		resp[rem].pop_back();
		qtd[rem]--;
		if (qtd[rem] == 0) pos.erase(rem);
	    }
	    else if (tp > 0 && exp >= day) {
		resp[day].pb(tp);
		pos.insert(day);
		qtd[day]++;
	    } else if (tp > 0 && exp < day) lim++;
	}
	day++;
	debug("\n");
    }

    day = 0;
    vector<int> ans;
    for (int i = 0; i < (n + m); i += k) {
	if ((int)resp[day].size() > 0) {
	    for (auto e : resp[day]) {
		ans.pb(e);
	    }
	}
	day++;
    }
    
    printf("%d\n", ans.size());
    for (int e : ans)
	printf("%d ", e);
    
    if (!ans.empty()) printf("\n");
    return 0;
}


