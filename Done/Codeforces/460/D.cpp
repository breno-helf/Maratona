#include<bits/stdc++.h>
using namespace std;

const int MAX = 312345;

int n, m;
vector<int> adj[MAX];
char L[MAX];
int points[MAX][33];
int mrk[MAX], ind[MAX];
int stk[MAX];

int dfs(int u) {
  mrk[u] = 1;
  stk[u] = 1;

  for (auto v : adj[u]) {
    if (!mrk[v]) {
      if (dfs(v)) return 1;
    } else if (stk[v]) {
      return 1;
    }
  }

  stk[u] = 0;
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf(" %c", &L[i]);
  }
  
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    ind[y]++;
  }

  queue<int> Q;
  
  for (int i = 1; i <= n; i++) {
    if (!ind[i]) Q.push(i);
    
    if (!mrk[i]) {
      int ret = dfs(i);
      
      if (ret) {
        printf("-1\n");
        return 0;
      }
    }
  }

  int resp = 0;
  
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    
    points[u][L[u] - 'a']++;
    resp = max(resp, points[u][L[u] - 'a']);   
    
    for (int v : adj[u]) {
      for (int c = 0; c <= (int)('z' - 'a'); c++) {
        points[v][c] = max(points[v][c], points[u][c]);
      }
      ind[v]--;
      if (!ind[v]) Q.push(v);
    }
  }

  printf("%d\n", resp);
}
