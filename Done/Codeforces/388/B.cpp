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

const int MAXN=1231321;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

inline int cmp(int x, double y = 0, int tol = 0) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  int x, y;
  point(int xx = 0, int yy = 0): x(xx), y(yy) {}
  point operator +(point q) { return point(x + q.x, y + q.y); }
  point operator -(point q) { return point(x - q.x, y - q.y); }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator ==(point q) const { return cmp(q) == 0; }
  bool operator !=(point q) const { return cmp(q) != 0; }
  bool operator < (point q) const { return cmp(q) < 0; }
}v[10];
int A;

set<point> resp;

point d1, d2;

int main() {
  for(int i = 0; i < 3; i++) {
    scanf("%d%d", &v[i].x, &v[i].y);
  }
  d1 = v[0] - v[1];
  d2 = v[0] - v[2];

  resp.insert(v[2] + d1);
  resp.insert(v[2] - d1);
  resp.insert(v[1] + d2);
  resp.insert(v[1] - d2);

  printf("%d\n", (int)resp.size());
  for(point e : resp) {
    printf("%d %d\n", e.x, e.y);
  }
  
}


