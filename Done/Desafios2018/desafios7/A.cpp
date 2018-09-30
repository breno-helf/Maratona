#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

vector<int> adj[MAX];

int heigth[MAX], cnt[MAX];

void dfs(int u, int p) {
    heigth[u] = heigth[p] + 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    cnt[heigth[u]]++;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1, 0);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] % 2 == 1) ans++;
    }
    cout << ans << '\n';
}
