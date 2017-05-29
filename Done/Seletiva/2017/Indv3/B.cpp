#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const ld  EPS = 1e-5;

int n;
ld t[MAX], v[MAX];
ld resp;

inline ld calc (ld T) {
  ld f = 1e18;
  ld l = 0;
  
  for (int i = 0; i < n; i++) {
    ld cur = (T - t[i]) * v[i];
    f = min(f, cur);
    l = max(l, cur);
  }
  return (l - f);
}

int main () {
  //cin.sync_with_stdio(false);
  //cin.tie(0);
  
  while (true) {
    scanf ("%d", &n);
    //cin >> n;
    
    if (n == 0) break;
    ld st = 0;
    for (int i = 0; i < n; i++) {
      scanf ("%lf %lf", t + i, v + i);    
      //cin >> t[i] >> v[i];
      
      st = max(st, t[i]);
    }

    if (n == 1) {
      printf ("%.3lf\n", 0);
      //cout << fixed << setprecision(3) << (ld)0 << '\n';
      continue;
    }
    
    ld l = st, r = 1e10;

    ld L = -1;
    
    resp = calc(st);
    for (int i = 0; i < 150; i++) {
      // ld m1 = (l + r) / 3.;
      // ld m2 = 2. * (l + r) / 3.;

      // ld l1 = calc (m1);
      // ld r1 = calc (m2);

      ld M = (l + r) / 2.;
      ld R = calc(M);
      ld Rp = calc(M + EPS);

      if (R < Rp) {
	r = M;
      } else {
	l = M;
      }

      resp = min(resp, min(R, Rp));
    }
    printf ("%.3lf\n", resp);
    //cout << fixed << setprecision(3) << resp << '\n';
  }

  return 0;
}
