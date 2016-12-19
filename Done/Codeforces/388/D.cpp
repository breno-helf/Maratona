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

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, q;
int mx[MAXN];

vector<int> a[MAXN];

set<pii> s;

pii query() {
  pii ret;
  int id = 0, m = 0, ss = 0;
  set<pii>::iterator lst;
  set<pii>::iterator ant;
  if(s.size()) {
    lst = prev(s.end());
  }
  if(s.size() > 1)
    ant = prev(lst);
  
  if(s.size()) {
    id = lst->second;
    m = lst->first;
    if(s.size() > 1)
      ss = ant->first;
  }
  if(m > 0)
    m = *(upper_bound(a[id].begin(), a[id].end(), ss));
  ret = mp(m, id);
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int id, b;
    scanf("%d%d", &id, &b);
    a[id].pb(b);
  }
  for(int i = 1; i <= n; i++) {
    if(a[i].size()) {
      mx[i] = a[i][a[i].size() - 1];
      s.insert(mp(mx[i], i));
    }
  }

  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int k;
    vector<int> id;
    scanf("%d", &k);
    for(int j = 0; j < k; j++) {
      int l;
      scanf("%d", &l);
      if(mx[l]) {
        s.erase(mp(mx[l], l));
        id.pb(l);
      }
    }
    pii resp = query();
    if(resp.second)
      printf("%d %d\n", resp.second, resp.first);
    else
      printf("0 0\n");
    for(auto e : id)
      s.insert(mp(mx[e], e));
  }
}


