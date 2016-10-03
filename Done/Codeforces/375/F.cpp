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

const int MAXN=412345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, s, t, ds, dt;
int es, et, junt[MAXN][2];
pii ed[MAXN];
int h[MAXN], pai[MAXN];
vector<pii> add, last;
vector<pii> resp;
int cmp;

int raiz(int x) {
  if(pai[x] == x) return x;
  else return pai[x] = raiz(pai[x]);
}

void une(int a, int b) {
  a = raiz(a);
  b = raiz(b);
  if(a == b) return;
  else {
    cmp--;
    if(h[a] < h[b]) swap(a, b);
    if(h[a] == h[b]) h[a]++;
    pai[b] = a;
  }
}

int con(int a, int b) {
  return (raiz(a) == raiz(b));
}

int main() {
  es = et = 0;
  scanf("%d%d", &n, &m);
  for(int i = 0; i <= n; i++) {
    pai[i] = i;
    h[i] = 1;
  }
  
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &ed[i].first, &ed[i].second);
  }
  scanf("%d%d%d%d", &s, &t, &ds, &dt);
  memset(junt, -1, sizeof(junt));
  cmp = n;
  
  for(int i = 0; i < m; i++) {
    int a, b;
    a = ed[i].first;
    b = ed[i].second;
    
    if(a == s || a == t || b == s || b == t) {
      if((a == s && b == t) || (a == t && b == s)) last.pb(mp(a,b));
      else add.pb(mp(a, b));
    }
    else {
      //debug("HI\n");
      if(!(con(a, b))) {
	une(a, b);
	resp.pb(mp(a, b));
      }
    }

  }

  for(int i = 0; i < (int)add.size(); i++) {
    pii e = add[i];
    
    if(e.first == s || e.second == s) {
      if(e.first == s) {
	if(junt[e.second][0] == -1) junt[e.second][0] = i;
	//else junt[e.second][0] = -INF;
      }
      else {
	if(junt[e.first][0] == -1) junt[e.first][0] = i;
	//else junt[e.first][0] = -INF;
      }
    }
    if(e.first == t || e.second == t) {
      if(e.first == t) {
	if(junt[e.second][1] == -1) junt[e.second][1] = i;
	//else junt[e.second][1] = -INF;
      }
      else {
	if(junt[e.first][1] == -1) junt[e.first][1] = i;
	//else junt[e.first][1] = -INF;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(junt[i][0] >= 0 && (junt[i][1] == -1)) {
      int a = add[junt[i][0]].first;
      int b = add[junt[i][0]].second;

      if(!(con(a, b)) && es < ds) {
	une(a, b);
	resp.pb(mp(a, b));
	es++;
      }
    }
    if(junt[i][1] >= 0 && (junt[i][0] == -1)) {
      int a = add[junt[i][1]].first;
      int b = add[junt[i][1]].second;
      
      if(!(con(a, b)) && et < dt) {
	une(a, b);
	resp.pb(mp(a, b));
	et++;
      }
    }
  }
  
  for(auto e : add) {
    if(!(con(e.first, e.second))) {
      //debug("hi\n");
      if(e.first == s || e.second == s)
	if(es == ds) continue;
      if(e.first == t || e.second == t)
	if(et == dt) continue;
      
      une(e.first, e.second);
      resp.pb(mp(e.first, e.second));
      if(e.first == s || e.second == s) es++;
      if(e.first == t || e.second == t) et++;
    }
  }
  for(auto e : last) {
    if(!(con(e.first, e.second))) {
      if(e.first == s || e.second == s)
	if(es == ds) continue;
      if(e.first == t || e.second == t)
	if(et == dt) continue;
      
      une(e.first, e.second);
      resp.pb(mp(e.first, e.second));
      if(e.first == s || e.second == s) es++;
      if(e.first == t || e.second == t) et++;
    }
  }
 
  
  if(cmp == 1) {
    puts("Yes");
    for(auto e : resp)
      printf("%d %d\n", e.first, e.second);
  }
  else puts("No");
  return 0;
}
