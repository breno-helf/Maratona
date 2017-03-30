//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX], t;

int main () {
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {
	scanf("%d", &n);
	int sum = (n * (n - 1)) / 2;
	int resp = 0, tot = 0, last = 0;

	for (int i = 0; i < n; i++) {
	    scanf("%d", &a[i]);
	    if (a[i] >= n) {
		resp += a[i] - (n - 1);
		a[i] = n - 1;
	    }
	}
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
	    int st = max(last, (i * (i + 1)) / 2 - tot);
	    int ed = ((n * (n - 1))/2 - tot) / (n - i);
	    debug("-- %d %d\n", st, ed);
	    last = st;
	    for (int k = st; k <= ed; k++)
		if (abs(a[i] - k) < abs(a[i] - last)) last = k;
	    tot += last;
	    resp += abs(a[i] - last);
	}
	debug("\n%d\n\n", tot);
	assert(tot == sum);
	printf("%d\n", resp);
    }    
}

