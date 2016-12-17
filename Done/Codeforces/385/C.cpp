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

int n, m, k;
vector<int> adj[MAXN];
int c[MAXN], num[MAXN];
int marc[MAXN];

int dfs(int u) {
  if(marc[u]) return 0;
  marc[u] = 1;
  int ret = 1;
  for(auto v : adj[u]) {
    if(!marc[v])
      ret += dfs(v);
  }
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < k; i++) {
    scanf("%d", &c[i]);
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int tot = 0, mx = 0, id;
  for(int i = 0; i < k; i++) {
    num[i] = dfs(c[i]);
    tot += num[i];
    if(num[i] > mx) {
      mx = num[i];
      id = i;
    }
  }
  int resp = 0;
  for(int i = 0; i < k; i++) {
    if(i == id) {
      resp += ((num[i] + n - tot)*(num[i] + n - tot - 1))/2;      
    }
    else {
      resp += (num[i]*(num[i] - 1))/2;
    }
  }    
  printf("%d\n", resp - mx);
  
  //  printf("%d\n", (n - k)*(n - k - 1)/2 + (n - k) - m);
}
