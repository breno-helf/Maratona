//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int n;
vector<pii> adj[MAX];
queue<int> leaves;
int mrk[MAX], deg[MAX]; // marking edges
int ans[MAX];

void pop_fast(vector<pii>& v, int pos) {
   int n = v.size();
   swap(v[pos], v[n - 1]);
   v.pop_back();
}


int main() {
   scanf("%d", &n);

   for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);

      deg[u]++;
      deg[v]++;
      
      adj[u].push_back(pii(v, i));
      adj[v].push_back(pii(u, i));     
   }

   for (int i = 1; i <= n; i++) {
      if (deg[i] == 1) {
         leaves.push(i);
      }
   }

   int cur = 0;

   while (!leaves.empty()) {
      int u = leaves.front();
      leaves.pop();
      pii edge = pii(-1, -1);
      //debug("Looking edges of %d\n", u);
      for (pii e : adj[u]) {
         if (mrk[e.second] == 0) {
            edge = e;
            mrk[e.second] = 1;            
         }
      }
      //debug("Picked edge %d %d\n", edge.first, edge.second);
      if (edge == pii(-1, -1)) continue;
      int v = edge.first, id = edge.second;
      deg[v]--;
      ans[id] = cur++;
      if (deg[v] == 1)
         leaves.push(v);
   }

   for (int i = 1; i < n; i++)
      printf("%d\n", ans[i]);
}
