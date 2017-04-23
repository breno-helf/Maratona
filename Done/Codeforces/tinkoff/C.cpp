//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

// Geometry Header
const ld EPS = 1e-11;
const ld PI = acos(-1);

inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    ld x, y;
    point(ld a, ld b): x(a), y(b) {}
    point(): x(0.0), y(0.0) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(ld t) { return point(x * t, y * t); }
    point operator /(ld t) { return point(x / t, y / t); }
    //a*b = |a||b|cos(ang) //dot product
    ld operator *(point q) {return x * q.x + y * q.y;}
    //a%b = |a||b|sin(ang) //modulo do cross
    ld operator ^(point q) {return x * q.y - y * q.x;}
    ld polar() { return ((y > - EPS) ? atan2(y,x) : 2 * PI + atan2(y, x)); }
    ld mod() { return sqrt(x * x + y * y); }
    ld mod2() { return (x * x + y * y); }
    point rotate(ld t) {
	return point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
    }
    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
};

typedef vector<point> polygon;

inline int ccw(point p, point q, point r) {
    return cmp((p - r) ^ (q - r));
}

//Decide se q esta sobre o segmento fechado pr.
bool between(point p, point q, point r) {
    return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

//\angle(p,q,r)| e o menor angulo entre os vetores u(p-q) e v(r-q)
// p->q->r virar pra esquerda => angle(p,q,r) < 0
inline ld angle(point p, point q, point r) {
    point u = p - q, v = r - q;
    return atan2(u ^ v, u * v);
}
// Calcula a distancia do ponto r ao segmento pq.
ld seg_distance(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    ld a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, b + c) >= 0) return sqrt(b);
    else return fabs(A ^ B) / sqrt(c);
}

// Classifica o ponto p em relacao ao poligono T.
// Retorna 0, -1 ou 1 dependendo se p esta no exterior, na fronteira
// ou no interior de T, respectivamente.
int in_poly(point p, polygon& T) {
    ld a = 0; int N = T.size();
    for (int i = 0; i < N; i++) {
	if (between(T[i], p, T[(i+1) % N])) return -1;
	a += angle(T[i], p, T[(i+1) % N]);
    }
    return cmp(a) != 0;
}

//Decide se os segmentos fechados pq e rs tem pontos em comum
bool seg_intersect(point p, point q, point r, point s) {
    point A = q - p, B = s - r, C = r - p, D = s - q;
    int a = cmp(A ^ C) + 2 * cmp(A ^ D);
    int b = cmp(B ^ C) + 2 * cmp(B ^ D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}

//Encontra o ponto de intersecao das retas pq e rs
point line_intersect(point p, point q, point r, point s) {
    point a = q - p, b = s - r, c = point(p ^ q, r ^ s);
    return point(point(a.x, b.x) ^ c, point(a.y, b.y) ^ c) / (a ^ b);
}

typedef pair<point, point> mice;

int n;

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    ld x1, y1, x2, y2;
 
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    polygon rec;
    rec.pb(point(x1, y1));
    rec.pb(point(x1, y2));
    rec.pb(point(x2, y2));
    rec.pb(point(x2, y1));
    vector<mice> M;

    ld dist = 0;
    bool ok = true, z = true;
    
    for (int i = 0; i < n; i++) {
	ld rx, ry, vx, vy;
	cin >> rx >> ry >> vx >> vy;
	M.pb(mice(point(rx, ry), point(vx, vy)));

	if (in_poly(M[i].first, rec) > 0) {
	    continue;
	}
	ld cur = 1e18;
	ld mul = 1e6 / (M[i].second.mod());
	for (int k = 0; k < 4; k++) {
	    if (seg_intersect(M[i].first - M[i].second * mul, M[i].first + M[i].second * mul, rec[k], rec[(k + 1) % 4])) {
		ld nx = (line_intersect(M[i].first - M[i].second * mul, M[i].first + M[i].second * mul, rec[k], rec[(k + 1) % 4]) - M[i].first).mod() / (M[i].second).mod();
		cur = min(cur, nx);
	    }
	}

	z = false;
	
	if (cur == 1e18) {
	    ok = false;
	    break;
	}
	
	if (cur > dist) {
	    dist = cur;
	}
    }

    if (!ok) {
	cout << -1 << '\n';
	return 0;
    }

    if (z) {
	cout << 0 << '\n';
	return 0;
    }
    
    ld resp = dist + 1e-11;
    
    ok = true;
    for (int i = 0; i < n; i++) {
	if (in_poly(M[i].first + M[i].second * resp, rec) <= 0) {
	    ok = false;
	}	
    }

    if (ok) {
	cout << fixed << setprecision(8) << resp << '\n';
    } else {
	cout << -1 << '\n';
    }
    return 0;
}

