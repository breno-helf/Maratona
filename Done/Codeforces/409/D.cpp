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

const double eps = 1e-9;

inline int cmp(double x, double y = 0, double tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point (double X = 0.0 , double Y = 0.0): x(X), y(Y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
	
    double operator *(point q) { return (x * q.x + y * q.y); }
    double operator %(point q) { return (x * q.y - y * q.x); }
    
    double mod() { return sqrt(x * x + y * y); }
    double mod2() { return (x * x + y * y); }
    
    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }
};

// Distancia do ponto r ao segmento pq
double seg_distance(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, b + c) >= 0) return sqrt(b);
    else return fabs(A % B) / sqrt(c);
}

int n;
vector<point> P;

bool test(double r) {
    for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n; j++)
	    if ((P[i] - P[j]).mod() <= 2 * r) return false; 
    
    for (int i = 0; i < n; i++) {
	point R = P[i];
	point p = P[(i - 1 + n) % n];
	point q = P[(i + 1) % n];
	if (seg_distance(p, q, R) <= 2 * r) return false;
    }
    return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	    double x, y;
	    scanf("%lf %lf", &x, &y);
	    P.pb(point(x, y));
	}

	double l = 0, r = 1e9;
	int it = 0;
	while (it < 200) {
	    it++;
	    double mid = (l + r) / 2;

	    if (test(mid)) l = mid;
	    else r = mid;	
	}

	printf("%.8lf\n", r);
    }
