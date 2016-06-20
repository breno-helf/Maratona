//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair
#define time BEMFEIA

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

vector<int> adj[MAXN];

vector<int> cmp[MAXN];

ll p[MAXN], n, m, marc[MAXN], men[MAXN], qtd[MAXN];

int low[MAXN], d[MAXN], st[MAXN], sn, time, num;

// Tarjan
void scc(int u){
  st[sn++] = u;
  low[u] = d[u] = time++;
  marc[u] = 1;
  for(int v : adj[u]){
    if(!marc[v]){
      scc(v);
      low[u] = min(low[u],low[v]);
    }
    else{
      low[u] = min(low[u],d[v]);
    }
  }
  if(low[u] == d[u]){
    int a = -1;
    while(a!=u){
      a = st[sn-1];
      if(p[a]<men[num]){
	men[num] = p[a];
	qtd[num] = 1;
      }
      else if(p[a]==men[num]) qtd[num]++;
      cmp[num].pb(a);
      d[a] = INF;
      --sn;
    }
    num++;
  }
}

int main(){
  num = 0;
  scanf("%I64d", &n);
  memset(men,INF,sizeof(men));
  for(int i=1;i<=n;i++) scanf("%I64d", &p[i]);   
  scanf("%d", &m);
  for(int i=0;i<m;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
  }
  for(int i=1;i<=n;i++){
    if(!marc[i]){
      scc(i);
    }
  }
  ll resp = 0;
  ll frm = 1;
  for(int i=0;i<num;i++){
    resp += men[i];
    frm *= qtd[i];
    frm %= MOD;
  }
  printf("%I64d %I64d\n", resp, frm);
  return 0;
}
