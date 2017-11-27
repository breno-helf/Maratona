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

ll tot;
int n, a[MAX];
int L, R, M;
int f;
multiset<int> S;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", a + i);
	tot += a[i];
	S.insert(a[i]);
    }

    sort(a, a + n);
    
    if (tot % n == 0) f = 0;
    else f = tot % n;

    M = tot / n; 
    L = R = 0;
    int resp = 0;
    
    for (int i = n - 1; i  >= 0; i--) {
	if (f) {
	    resp += abs(M + 1 - a[i]);
	    f--;
	} else resp += abs(M - a[i]);
    }
    debug("--> %d\n", resp);
    printf("%d\n", resp / 2);
}
