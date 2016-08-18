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

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, num;
int indeg[MAXN];

vector<int> adj[MAXN];

vector<int> toposort;

priority_queue<int> pq;

int main (){
  num = 0;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].pb(b);
    indeg[b]++;
  }
  for(int i = 1; i <= n; i++) if(!indeg[i]) pq.push(-i);

  while(!pq.empty()) {
    int atual = - pq.top();
    pq.pop();
    toposort.pb(atual);
    num++;
    for(int v : adj[atual]) {
      indeg[v]--;
      if(!indeg[v]) pq.push(-v);
    }
  }
  o
  if(num!=n) puts("Sandro fails."); ///Breno Também.
  else for(int i = 0; i < n; i++) printf("%d%c", toposort[i], (i==n-1) ? '\n' : ' ');
  printf("\n");
  return 0;  
}












