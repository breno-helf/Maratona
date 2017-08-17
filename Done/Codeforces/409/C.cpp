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

const double lim = 1e10 + 10;

int n;
double p, a[MAX], b[MAX];

bool test(double lambda) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
	sum += max(lambda * a[i] - b[i], 0.0);
    }
    return sum <= lambda * p;
}

int main() {
    scanf("%d%lf", &n, &p);

    for (int i = 0; i < n; i++) {
	scanf("%lf%lf", a + i, b + i);
    }

    double l = 0, r = lim + 10;
    int it = 0;
    while (it < 200) {
	it++;
	double mid = (l + r) / 2;
	if (test(mid)) l = mid;
	else r = mid;
    }
    //debug("--> %.4lf %.4lf\n", l, r);
    if (r >= lim) printf("-1\n");
    else printf("%.8lf\n", r);
}

