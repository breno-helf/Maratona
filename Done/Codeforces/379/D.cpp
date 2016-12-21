//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair
#define ins insert
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=512345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, kx, ky;
map<pii, char> p;
map<int, set<int> > ox, oy, nox, noy;
map<int, set<int> > ad, sb, nad, nsb;
int main() {
  scanf("%d", &n);
  scanf("%d%d", &kx, &ky);
  for(int i = 0; i < n; i++) {
    int a, b;
    char c;
    scanf(" %c", &c);
    scanf("%d%d", &a, &b);
    if(a == kx || b == ky || (a + b) == (kx + ky) || (a - b) == (kx - ky)) {
      p[mp(a, b)] = c;
      ox[a].ins(b);
      oy[b].ins(a);
      nox[a].ins(-b);
      noy[b].ins(-a);
      ad[a + b].ins(a);
      sb[a - b].ins(a);
      nad[a + b].ins(-a);
      nsb[a - b].ins(-a);
    }
  }
  char nt, s, e, o, no, ne, so, se;
  nt = s = e = o = no = ne = so = se = 0;
  if(ox[kx].size()) {
    if(ox[kx].upper_bound(ky) != ox[kx].end())
      nt = p[mp(kx, *(ox[kx].upper_bound(ky)))];
    if(nox[kx].upper_bound(-ky) != nox[kx].end())
      s = p[mp(kx, -(*(nox[kx].upper_bound(-ky))))];
  }
  if(oy[ky].size()) {
    if(oy[ky].upper_bound(kx) != oy[ky].end()) 
      o = p[mp(*(oy[ky].upper_bound(kx)), ky)];
    if(noy[ky].upper_bound(-kx) != noy[ky].end()) 
      e = p[mp(-(*(noy[ky].upper_bound(-kx))), ky)];
  }
  if(ad[kx + ky].size()) {

    if(ad[kx + ky].upper_bound(kx) != ad[kx + ky].end()) {
      int f = *(ad[kx + ky].upper_bound(kx));
      se = p[mp(f, kx + ky - f)];
    }
    if(nad[kx + ky].upper_bound(-kx) != nad[kx + ky].end()) {
      int f = *(nad[kx + ky].upper_bound(-kx));
      f *= -1;
      no = p[mp(f, kx + ky - f)];
    }    
  }
  if(sb[kx - ky].size()) {

    if(sb[kx - ky].upper_bound(kx) != sb[kx - ky].end()) {
      int f = *(sb[kx - ky].upper_bound(kx));
      so = p[mp(f, f - (kx - ky))];
    }
    if(nsb[kx - ky].upper_bound(-kx) != nsb[kx - ky].end()) {
      int f = *(nsb[kx - ky].upper_bound(-kx));
      f *= -1;
      ne = p[mp(f, f - (kx - ky))];
    }
  }
  bool resp = false;
  if(nt == 'R' || nt == 'Q')
    resp = true;
  if(s == 'R' || s == 'Q')
    resp = true;
  if(e == 'R' || e == 'Q')
    resp = true;
  if(o == 'R' || o == 'Q')
    resp = true;
  if(ne == 'B' || ne == 'Q')
    resp = true;
  if(no == 'B' || no == 'Q')
    resp = true;
  if(se == 'B' || se == 'Q')
    resp = true;
  if(so == 'B' || so == 'Q')
    resp = true;
  if(resp)
    puts("YES");
  else
    puts("NO");
}

