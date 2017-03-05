//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, double> pdd;

const int MAX = 61234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

pdd x[MAX];

int n;

double calc (double pos) {
    double ret = 0;
    for (int i = 0; i < n; i++)
	ret = max(ret, abs(x[i].first - pos) / x[i].second);
    return ret;
}

bool go (double pos) {
    double esq = 0, dir = 0;
    int i;
    for (i = 0; x[i].first < pos; i++) {
	esq = max(esq, (pos - x[i].first) / x[i].second); 
    }
    for (; i < n; i++) {
	dir = max(dir, (x[i].first - pos) / x[i].second);
    }
    return (esq < dir);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
	scanf ("%lf", &x[i].first);
    for (int i = 0; i < n; i++)
	scanf ("%lf", &x[i].second);
    sort(x, x + n);
    double l = x[0].first, r = x[n - 1].first;
    int cnt = 0;
    while (cnt < 80) {
	double mid = (l + r) / 2; 
	if (go(mid)) l = mid;
	else r = mid;
	cnt++;
    }
    printf("%.7lf\n", calc(l));
}

