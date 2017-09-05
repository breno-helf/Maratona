//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1000 + 4;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const double eps = 1e-9;
const double Pi = acos(-1);

inline int cmp(double x, double y = 0, double tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x[5];
    point(double a = 0, double b = 0, double c = 0,
	  double d = 0, double e = 0) {
	x[0] = a;
	x[1] = b;
	x[2] = c;
	x[3] = d;
	x[4] = e;
    }

    point operator -(point q) {
	return point(x[0] - q.x[0], x[1] - q.x[1], x[2] - q.x[2],
		     x[3] - q.x[3], x[4] - q.x[4]);
    }
    
    double operator *(point q) {
	double ret = 0;
	for (int i = 0;  i < 5; i++) ret += q.x[i] * x[i];
	return ret;
    }
    
    double mod() {
	point B = point(x[0], x[1], x[2], x[3], x[4]);
	point A = point(x[0], x[1], x[2], x[3], x[4]);
	return sqrt(A * B);
    }

    int cmp(point q) const {
	for (int i = 0; i < 5; i++) {
	    if (int t = ::cmp(x[i], q.x[i])) return t;
	}
	return 0;
    }

    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
};

int n;
double dot[MAX][MAX];
point v[MAX];
int mrk[MAX];

inline bool test(int i, int j, int k) {
    double num = (dot[j][k] - dot[i][j] - dot[i][k] + dot[i][i]);
    double den = sqrt(dot[j][j] - dot[i][j] - dot[i][j] + dot[i][i]) * sqrt(dot[k][k] - dot[i][k] - dot[i][k] + dot[i][i]);
    return cmp(acos(num / den), Pi/2) < 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	double a, b, c, d, e;
	scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);
	v[i] = point(a, b, c, d, e);
    }
    
    for (int i = 0; i < n; i++)
	for (int j = i; j < n; j++)
	    dot[i][j] = dot[j][i] = v[i] * v[j];

    vector<int> resp;
    
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    for (int k = j + 1; k < n; k++) {
		//if (j == i || k == i || k == j) continue;
		
		if (!mrk[i] && test(i, j, k)) {
		    mrk[i] = 1;
		    //debug("Markei %d\n", i);
		}									    
		if (!mrk[j] && test(j, i, k)) {
		    mrk[j] = 1;
		    //debug("Markei %d\n", j);
		}									    
		if (!mrk[k] && test(k, i, j)) {
		    mrk[k] = 1;
		    //debug("Markei %d\n", k);
		}									    
	    }
	}
	if(!mrk[i]) resp.pb(i);
    }
    printf("%d\n", (int)resp.size());
    for (auto i : resp) printf("%d\n", i + 1);
    return 0;
}
