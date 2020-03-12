//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<int> adj[MAX];
int n, a[MAX];
int res[MAX];
int DP[MAX], revDP[MAX], parent[MAX];

void dfs(int u, int p) {
   int ans = (a[u] == 1) ? 1 : -1; 
   for (int v : adj[u]) {
      if (v != p) {
         parent[v] = u;
         dfs(v, u);
         if (DP[v] > 0) ans += DP[v];         
      }                   
   }

   DP[u] = ans;
}

// 1 is always root
void dfsR(int u, int p) {
   revDP[u] = max(0, revDP[p]) + ((a[u] == 1) ? 1 : -1);

   res[u] = max(0, revDP[p]) + DP[u];
   //debug("res[%d] = %d -- revDP[%d] = %d -- DP[%d] = %d\n", u, res[u], p, revDP[p], u, DP[u]);
   
   for (int v : adj[u]) {
      if (v != p) {
         //debug("Added val for %d (revDP %d) is %d\n", u, revDP[u], max(0, DP[u] - max(DP[v], 0) - ((a[u] == 1) ? 1 : -1)));
         revDP[u] += max(0, DP[u] - max(DP[v], 0) - ((a[u] == 1) ? 1 : -1));
         dfsR(v, u);
         revDP[u] -= max(0, DP[u] - max(DP[v], 0) - ((a[u] == 1) ? 1 : -1));
      }
   }
}

int main() {
   scanf("%d", &n);
   
   for (int i = 1; i <= n; i++)
      scanf("%d", a + i);

   for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   //debug("-> Graph was read\n");
   
   dfs(1, 0);

   //debug("-> First DFS\n");

   dfsR(1, 0);

   //debug("-> Second DFS\n");
   
   for (int i = 1; i <= n; i++) {
      //int ans;
      //revDP[parent[i]] = max(0, DP[parent[i]] - max(DP[i], 0));
      
      //ans = DP[i] + max(revDP[parent[i]], 0);
      //debug("DP[%d] = %d, parent[%d] = %d, revDP[%d] = %d\n", i, DP[i], i, parent[i], parent[i], revDP[parent[i]]); 
      
      printf("%d ", res[i]);
   }
   

   printf("\n");
}
