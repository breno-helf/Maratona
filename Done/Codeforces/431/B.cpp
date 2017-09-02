//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct point {
    ll x, y;
    point(ll X = 0, ll Y = 0): x(X), y(Y) {}

    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }

    ll operator ^(point q) { return (x * q.y - y * q.x); }
    
};

inline int ccw(point p, point q, point r) {
    ll val = (p - r) ^ (q - r);
    if (val < 0) return -1;
    if (val > 0) return 1;
    return 0;
}

inline bool parallel(point p, point q, point r, point s) {
    ll val = (p - q) ^ (r - s);
    return (val == 0);
}

int n;

point v[MAX];

pair<point, point> r1, r2;

int q1, q2;


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	ll y;
	scanf("%lld", &y);
	v[i] = point((ll)(i + 1LL), y);
    }

    
    bool ok = false;

    // printf(">>> %lld %lld\n", v[0].x, v[0].y);
    // printf(">>> %lld %lld\n", v[2].x, v[2].y);
    // printf(">>> %lld %lld\n", v[4].x, v[4].y);

    // printf("%lld\n", (v[0] - v[4]) ^ (v[2] - v[4]));
    // printf("--> %d %s\n", ccw(v[0], v[2], v[4]), ccw(v[0], v[2], v[4]) == 0 ? "colinear" : "bug");
    
    for (int k = 1; k < n; k++) {
	r1 = mp(v[0], v[k]);
	q1 = 2;
	q2 = 0;

	//debug("Reta %lld %lld ate %lld %lld\n", v[0].x, v[0].y, v[k].x, v[k].y);
	
	for (int i = 1; i < n; i++) {
	    if (i == k) continue;
	    
	    if (ccw(r1.first, v[i], r1.second) == 0) {
		q1++;
		//debug("Adicionando reta %d na primeira\n", i);
	    } else {
		if (q2 == 0) {
		    r2.first = v[i];
		    q2++;
		    //debug("Adicionando reta %d na segunda\n", i);
		} else if (q2 == 1) {
		    r2.second = v[i];
		    q2++;
		    //debug("Adicionando reta %d na segunda\n", i);
		} else {
		    if (ccw(r2.first, v[i], r2.second) == 0) q2++;
			//debug("Adicionando reta %d na segunda\n", i);}
		}
	    }
	}

	//debug("%d %d\n", q1, q2);
	
	if (q1 + q2 == n && q2 != 0) {
	    if (q2 == 1) ok = true;
	    else if (parallel(r1.first, r1.second, r2.first, r2.second)) ok = true;
	}
    }
    
    r1 = mp(v[1], v[2]);

    q1 = 2;
    q2 = 0;
    
    //debug("Reta %lld %lld ate %lld %lld\n", v[0].x, v[0].y, v[k].x, v[k].y);
    
    for (int i = 0; i < n; i++) {
	if (i == 1 || i == 2) continue;
	
	if (ccw(r1.first, v[i], r1.second) == 0) {
	    q1++;
	    //debug("Adicionando reta %d na primeira\n", i);
	} else {
	    if (q2 == 0) {
		r2.first = v[i];
		q2++;
		//debug("Adicionando reta %d na segunda\n", i);
	    } else if (q2 == 1) {
		r2.second = v[i];
		q2++;
		    //debug("Adicionando reta %d na segunda\n", i);
	    } else {
		    if (ccw(r2.first, v[i], r2.second) == 0) q2++;
		    //debug("Adicionando reta %d na segunda\n", i);}
	    }
	}
    }
        
    if (q1 + q2 == n && q2 != 0) {
	if (q2 == 1) ok = true;
	else if (parallel(r1.first, r1.second, r2.first, r2.second)) ok = true;
    }
    
    if (ok) puts("Yes");
    else puts("No");
}
