#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

pll c[MAX];
pll d[MAX];
int n;

ll Q(ll x) {
    return x * x;
}

ll dist(pll a, pll b) {
    return (Q(a.first - b.first) + Q(a.second - b.second));
}

ll cross (pll a, pll b) {
    return a.first * b.second - a.second * b.first;
}

bool colinear(int i, int j, int k) {
    return (cross(pll(c[i].first - c[k].first, c[i].second - c[k].second), pll(c[j].first - c[k].first, c[j].second - c[k].second)) == 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	int a, b;
	scanf ("%d%d", &a, &b);
	c[i] = pll(a, b);
    }

    for (int i = 1; i <= n; i++) {
	d[i] = pll(dist(c[1], c[i]), i);
    }

    sort(d + 1, d + n + 1);
    //debug ("Test %s\n", colinear(1, 5, 3) ? "True" : "False");
    //for (int i = 1; i <= n; i++) debug ("-- %lld %lld\n", d[i].first, d[i].second);
    int k = 3;
    while (colinear(d[1].second, d[2].second, d[k].second) && k <= n) k++;
    
    printf("%lld %lld %lld\n", d[1].second, d[2].second, d[k].second);
	     
    return 0;
}

