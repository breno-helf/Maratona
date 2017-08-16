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

double n, a;
double d;
int main() {
    scanf("%lf%lf", &n, &a);
    d = ((n - 2) * 180 / n);
    double p = (n - 2);
    int id = 3;
    double cur = d / p, e = d / p;
    double m = 1e18;
    for (int i = id; i <= n; i++) {
	if (abs(cur - a) < m) {
	    m = abs(cur - a);
	    id = i;
	}
	cur += e;
    }
    printf("2 1 %d\n", id);
}

