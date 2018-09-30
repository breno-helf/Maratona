#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1e5 + 10;

int cancel[MAX];
int deg[MAX];
int invalid[MAX];
char s[20];

int main() {
    freopen("bureau.in", "r", stdin);
    freopen("bureau.out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf(" %s", s);
        if (strcmp(s, "cancel") == 0) {
            int v;
            scanf("%d", &v);
            cancel[i] = v;
            deg[v]++;
        }
    }

    vector<int> ans;
    queue<int> Q;
    
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) Q.push(i);
    }


    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (invalid[u]) {
            int v = cancel[u];
            deg[v]--;
            if (v > 0 && deg[v] == 0) Q.push(v);
        } else {
            int v = cancel[u];
            invalid[v] = 1;
            deg[v]--;
            if (v > 0 && deg[v] == 0) Q.push(v);
        }        
    }

    for (int i = 1; i <= n; i++) if (invalid[i] == 0) ans.push_back(i);
    
    printf("%d\n", (int)ans.size());
    for (int x : ans)
        printf("%d ", x);
    printf("\n");
}
