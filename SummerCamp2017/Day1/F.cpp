//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef double long double

const int MAXN=31234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;
const double eps = 1e-12;
const double Pi = acos(-1);

inline int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  double x, y;
  point(double x = 0, double y = 0): x(x), y(y) {}
  point operator +(point q) { return point(x + q.x, y + q.y); }
  point operator -(point q) { return point(x - q.x, y - q.y); }
  point operator *(double t) { return point(x * t, y * t); }
  point operator /(double t) { return point(x / t, y / t); }
  double operator *(point q) {return x * q.x + y * q.y;}
  //a*b = |a||b|cos(ang)
  double operator %(point q) {return x * q.y - y * q.x;}
  //a%b = |a||b|sin(ang)
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
  static point pivot;
};

point point::pivot;
typedef vector<point> polygon;

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

inline int ccw(point p, point q, point r) {
  return cmp((p - r) % (q - r));
}
//Projeta o vetor v sobre o vetor u (cuidado precisao)
point proj(point v, point u) {
  point p = u*((u*v) / (u*u));
  return p;
}

int t;
double lm, lg;

point sh[4];

int main() {
  cin >> t;
  for(int tt = 0; tt < t; tt++) {
    cin >> lm >> lg;
    for(int i = 0; i < 3; i++) {
      cin >> sh[i].x >> sh[i].y;      
    }
    
    if((sh[0] - sh[1])%(sh[1] - sh[2]) == 0) {
      double dist = max( (sh[0] - sh[1]).mod(), max( (sh[1] - sh[2]).mod(), (sh[0] - sh[2]).mod()));
      if(dist <= lm || dist <= 2*lg)
        puts("YES");
      else
        puts("NO");
      continue;
    }
    int resp = 0;
    
    for(int i = 0; i < 3; i++) {
      double dist;
      point a, b, c;
      if(!i) {
        a = sh[1];
        b = sh[2];
        c = sh[0];
      }
      else {
        a = sh[0];
        b = sh[i];
        c = sh[(i == 1) ? 2 : 1];
      }

      dist = (a - b).mod();
      
      if(dist >= 2*lg) {
        point d = a - b;
        if(proj(a + c, a + d) <= lm) {
          double pit = sqrt( (a - c).mod2() - proj(a + c, a + d).mod2() );
          if(pit <= (a - b).mod())
            resp = 1;
        }
      }
      if(dist >= lm) {
        point d = a - b;
        point pro = proj(a + c, a + d);
        if() {

          resp = 1;
        }
        
      }

    }
    if(resp)
      puts("YES");
    else
      puts("NO");
  }

}
