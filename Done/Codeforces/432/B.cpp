//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 31231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const double eps = 1e-9;
const double Pi = acos(-1);

inline int cmp(double x, double y = 0, double tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
    double x, y;
    point(double X = 0, double Y = 0): x(X), y(Y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) {return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
    double operator %(point q) {return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
    double polar() { return ((y > -eps) ? atan2(y,x) : 2*Pi + atan2(y,x)); }
    double mod() { return sqrt(x * x + y * y); }
    double mod2() { return (x * x + y * y); }
    point rotate(double t) {return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
};

point O;

inline double angle(point p, point q, point r) {
    point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}

inline int ccw(point p, point q, point r) {
    assert(cmp(p.x * (q.y - r.y) + q.x * (r.y - p.y) + r.x * (p.y - q.y)) == cmp((p - r) % (q - r)));
    return cmp((p - r) % (q - r));
}

int main() {
    point A, B, C;

    double x, y;
    scanf("%lf%lf", &x, &y);
    A = point(x, y);
    
    scanf("%lf%lf", &x, &y);
    B = point(x, y);
    
    scanf("%lf%lf", &x, &y);
    C = point(x, y);
    
    if ((B - A).mod2() == (B - C).mod2() && ccw(A, B, C) != 0) puts("Yes");
    else puts("No");

}
