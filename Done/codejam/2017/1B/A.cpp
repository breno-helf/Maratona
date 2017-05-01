//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<double, double> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
pii h[MAX]; // Horses, process for the slower to faster
double d;

bool cmp (pii a, pii b) {
    return a > b;
}

int main () {
    int T;
    scanf ("%d", &T);
    for (int t = 1; t <= T; t++) {
	scanf ("%lf %d", &d, &n);
	for (int i = 0; i < n; i++) {
	    scanf ("%lf %lf", &h[i].second, &h[i].first);
	}
	double m = 0;
	for (int i = 0; i < n; i++) {
	    double temp;
	    temp = (d - h[i].second) / (h[i].first);
	    m = max(temp, m);
	}
	//debug ("-- %lf\n", m);
	printf ("Case #%d: %lf\n", t, d / m);
    }
}

