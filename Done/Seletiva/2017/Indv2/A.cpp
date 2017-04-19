#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

// Geometry Header
inline int cmp(ll x, ll y = 0) {
    //return (x == y) ? 0 : ((x < y) ? -1 : 1);
    return (x <= y) ? (x < y) ? -1 : 0 : 1;
}

struct point {
    ll x, y;
    point(ll a, ll b): x(a), y(b) {}
    point(): x(0.0), y(0.0) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(ll t) { return point(x * t, y * t); }
    point operator /(ll t) { return point(x / t, y / t); }
    //a*b = |a||b|cos(ang) //dot product
    ll operator *(point q) {return x * q.x + y * q.y;}
    //a%b = |a||b|sin(ang) //modulo do cross
    ll operator ^(point q) {return x * q.y - y * q.x;}
    ll mod2() { return (x * x + y * y); }
    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    static point pivot;
};

point point::pivot;

typedef vector<point> polygon;

inline int ccw(point p, point q, point r) {
    return cmp((p - r) ^ (q - r));
}

// Comparacao radial.
// Obs: suponha tds pontos no vetor p[] = p[]-pivot, (pivot = min_elemento(p))
// tds ptos do novo p[] estarao no 1 e 4 quadrante ordenado no sentido anti-hor
bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot;
    ll R = P ^ Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}
// Determina o fecho convexo de um conjunto de pontos no plano.
// Destroi a lista de pontos T.
polygon convex_hull(vector<point>& T) {
    int j = 0, k, n = T.size(); polygon U(n);
    point::pivot = *min_element(T.begin(), T.end());
    sort(T.begin(), T.end(), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + T.begin(), T.end());
    for (int i = 0; i < n; i++) {
	// troque o >= por > para manter pontos colineares
	while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
	U[j++] = T[i];
    }
    U.erase(j + U.begin(), U.end());
    return U;
}

ll poly_area(polygon &T) {
    ll s = 0; int n = T.size();
    for (int i = 0; i < n; i++)
	s += T[i] ^ T[(i+1) % n];
    return s;
}

ll tri_area(point a, point b, point c) {
    ll A = ((b - a) ^ (c - a));
    return (A < 0) ? -A : A;
}

int ternary (int i, int j, int lo, int hi, polygon &C) {
    while ((hi - lo) >= 4) {
	int mid = (lo + hi) / 2;
	ll w1, w2;
	w1 = tri_area(C[i], C[j], C[mid]);
	w2 = tri_area(C[i], C[j], C[mid + 1 ]);

	debug ("&& %lld %lld --\n", w1, w2);
			
	if (w1 > w2)
	    hi = mid;
	else
	    lo = mid + 1;
    }

    ll w = 0;
    int ret = lo;
    for (int k = lo; k <= hi; k++) {
	ll q = tri_area(C[i], C[j], C[k]);
	if (q > w) {
	    w = q;
	    ret = k;
	}
    }
    return ret;
}

int main() {
    int t;
    for (scanf("%d", &t); t; t--) {
	int n;
	polygon P, C;
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
	    ll x, y;
	    scanf ("%lld %lld", &x, &y);
	    P.pb(point(x, y));
	}
	int ok = false;
	for (int i = 0; i < (n - 2); i++) {
	    if (ccw(P[i], P[i + 1], P[i + 2]) != 0) ok = true;
	}
	if (!ok) {
	    printf("0\n");
	    continue;
	}
	
	C = convex_hull(P);
	int tam = C.size();

	if (tam < 3) {
	    printf("0\n");
	    continue;
	}

	if (tam == 3) {
	    ll r = poly_area(C);

	    debug("Triangulo -- %lld\n", r);
	    printf("%lld", r / 2);
	    if (r % 2) printf(".5");
	    printf("\n");
	    continue;
	} else {
	    debug("Convex Hull - ");
	    for (int i = 0; i < tam; i++) {
		debug ("%lld %lld ** ", C[i].x, C[i].y);
		C.pb(C[i]);
	    }
	    debug("\n");
	    ll r = 0;
	    for (int i = 0; i < tam; i++) {
		for (int j = i + 2; j < tam; j++) {
		    int k1 = -1, k2 = -1;
		    polygon T;
		    T.pb(C[i]); T.pb(C[j]);
		    
		    k1 = ternary(i, j, i + 1, j - 1, C);
		    
		    k2 = ternary(i, j, j + 1, (tam - 1) + i, C);

		    T.pb(C[k1]); T.pb(C[k2]); 
		    debug (">> %d %d %d %d\n-- ", i, j, k1, k2);
		    for (int k = 0; k < 4; k++) {
			debug("%lld %lld |||| ", T[k].x, T[k].y);
		    }
		    sort(T.begin(), T.end(), radial_lt);
		    ll p = poly_area(T);
		    debug ("Area == %lld -- %d\n\n", p, (int)T.size());
		    r = max(r, p);
		}
	    }
	    debug("Quadrado -- %lld\n", r);

	    printf("%lld", r / 2);
	    if (r % 2) printf(".5");
	    printf("\n");
	}
    }
    
    return 0;
}
