//If you are trying to hack me I wish you can get it, Good Luck :D.
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

int n;
int a[MAX];
int b[MAX];
int mrk[MAX];
map<int, int> p;
vector<vector<int> > s;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", a + i);
	b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    
    for (int i = 1; i <= n; i++) {
	p[b[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
	if (mrk[i]) continue;
	vector<int> cur;
	
	while(p[a[i]] != i) {
	    int pos = p[a[i]];
	    mrk[pos] = 1;
	    cur.pb(pos);
	    swap(a[i], a[pos]);    
	}

	mrk[i] = 1;
	cur.pb(i);
	s.pb(cur);
    }

    printf("%d\n", (int)s.size());
    for (auto v : s) {
	printf("%d ", (int)v.size());
	for (int e : v) printf("%d ", e);
	printf("\n");
    }
    return 0;
}

