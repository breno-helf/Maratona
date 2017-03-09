//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct point {
    int x, y;
    point(int a, int b): x(a), y(b) {}
    point(): x(0), y(0) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(int t) { return point(x * t, y * t); }
    point operator /(int t) { return point(x / t, y / t); }
    //a*b = |a||b|cos(ang) //dot product
    int operator *(point q) {return x * q.x + y * q.y;}
    //a%b = |a||b|sin(ang) //modulo do cross
    int operator ^(point q) {return x * q.y - y * q.x;}
    int mod2() { return (x * x + y * y); }
};

int n;
point p[MAX];

inline int col (point& a, point& b, point& c) {
    return (b - c) ^ (a - b);
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf ("%d%d", &p[i].x, &p[i].y);
    }
    int resp = 0;
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    for (int k = j + 1; k < n; k++) {
		if (col(p[i], p[j], p[k])) resp++;
	    }
	}
    }
    printf("%d\n", resp);
}
