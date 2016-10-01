//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, a[MAXN], ord[MAXN];
ll acc[MAXN];
ll arv[10*MAXN];
unordered_map<ll, int> qtd;
unordered_map<ll, int> id;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    acc[i] = acc[i - 1] + a[i];
  }
  arv[1] = acc[n];
  int tam = 1;
  set<ll> sum;
  set<int> el;
  set<int>::iterator it;
  id[acc[n]] = 1;
  el.insert(n + 1);
  el.insert(0);
  sum.insert(-arv[1]);
  qtd[arv[1]]++;
  tam = 2;
  for(int i = 0; i < n; i++) {
    scanf("%d", ord + i);
    //acc[ord[i]] = 0;
    el.insert(ord[i]);
    it = el.find(ord[i]);
    int l = (*prev(it) + 1);
    int r = (*next(it) - 1);
    int k = id[acc[r] - acc[l - 1]];
    debug("--> %d %d %d\n", l, r, k);
    qtd[arv[k]]--;
    if(!(qtd[arv[k]])) {
      sum.erase(-arv[k]);
    }
    ll esq;
    ll dir;
    
    esq = acc[ord[i] - 1] - acc[l - 1]; 
    dir = acc[r] - acc[ord[i]];
    debug("==> %lld %lld\n", esq, dir);
    qtd[esq]++;
    qtd[dir]++;
    id[esq] = tam;
    id[dir] = tam + 1;
    arv[id[esq]] = esq;
    arv[id[dir]] = dir;
    tam += 2;
    sum.insert(-esq);
    sum.insert(-dir);
    ll resp = -(*(sum.begin()));
    printf("%lld\n", resp);
  }
}

