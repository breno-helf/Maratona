//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const double eps = 1e-9;

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

double R, D;

int n;

bool test(point p, double r) {
    double dist = p.mod();
    if (cmp(dist - r, R - D) >= 0 && cmp(dist + r, R) <= 0) return true;
    return false;    
}


int main() {
    scanf("%lf %lf", &R, &D);

    scanf("%d", &n);

    int ans = 0;
    
    for (int i = 0; i < n; i++) {
	double x, y, r;
	scanf("%lf %lf %lf", &x, &y, &r);
	if(test(point(x, y), r)) ans++;
    }

    printf("%d\n", ans);
}

