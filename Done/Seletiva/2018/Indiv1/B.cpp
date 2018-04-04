//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 51234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

const ll EPS = 0;
const double PI = acos(-1);

inline int cmp(ll x, ll y = 0, ll tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  ll x, y;
  point(ll a, ll b): x(a), y(b) {}
  point(): x(0LL), y(0LL) {}
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
};

typedef vector<point> polygon;

ll poly_area(polygon& T) {
  ll s = 0; int n = T.size();
  for (int i = 0; i < n; i++)
    s += T[i] ^ T[(i+1) % n];
  return llabs(s);
}

int n, q;
polygon P;
ll A[MAX];

int main() {
  int t = 0;
  while (true) {
    scanf("%d%d", &n, &q);
    if (n == 0 && q == 0) break;
    if (t) printf("\n");
    P.clear();
    memset(A, 0, sizeof(A));
    for (int i = 0; i < n; i++) {
      ll x, y;
      scanf("%lld %lld", &x, &y);
      P.pb(point(x, y));
    }

    ll total = poly_area(P);
    
    for (int i = 1; i < n; i++) {
      polygon cur;
      cur.pb(P[0]);
      cur.pb(P[i - 1]);
      cur.pb(P[i]);
      A[i] = A[i - 1];
      A[i] += poly_area(cur);
    }

    // debug("--> %lld\n", total);
    // for (int i = 0; i < n; i++) {
    //   printf("%lld ", A[i]);
    // }
    // printf("\n----------------------\n");
    
    for (int Q = 0; Q < q; Q++) {
      int a, b;
      polygon cur;
      scanf("%d %d", &a, &b);
      cur.pb(P[0]);
      cur.pb(P[a]);
      cur.pb(P[b]);
      ll resp = A[b] - A[a] - poly_area(cur);
      resp = min(resp, total - resp);
      printf("%lld.%d\n", resp / 2LL, (resp % 2LL) ? 5 : 0);
    }
    t++;
  }
  return 0;
}

