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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int t, x, y, p;

int q(int a) {
  return a*a;
}

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> p >> x >> y;
    double ang = p*360;
    ang /= 100;
    ang = ang*(acos(-1))/180.0;
    double ang2 = atan2((y - 50), (x - 50));
    if(ang2 < 0) ang2 += 360.0;
    cout << "Case #" << i + 1;
    if(((q(x - 50) + q(y - 50)) <= q(50)) && ang2 <= ang)
      cout << ": black\n";
    else
      cout << ": white\n";
    // (x + 0)² + (y + 0)² = r²
  }
  return 0;
}
