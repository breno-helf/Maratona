#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int MAXN = 1e5+10;

#define ix first
#define t second

int n;
vector<int> g[MAXN];
int w[MAXN];
ll t[MAXN];
ll bit[MAXN];
vector<pii> v;

void update(int x, ll delta) {
    while (x < MAXN) {
        bit[x] += delta;
        x += x&-x;
    }
}

ll query(int x) {
    ll ret = 0;
    while (x > 0) {
        ret += bit[x];
        x -= x&-x;
    }
    return ret;
}

int dfs(int cur, int par = 0) {
    v.push_back(pii(cur, 0));
    for (int next : g[cur]) {
        if (next != par) {
            dfs(next, cur);
        }
    }
    v.push_back(pii(cur, 1));
}

int main()
{
    scanf("%d", &n);

    int start;
    for (int i = 1,a; i <= n; i++) {
        scanf("%d %d %lld", &a, &w[i], &t[i]);
        if (a != -1)
            g[a].push_back(i);
        else
            start = i;
    }

    dfs(start);

    ll ans[n+1];
    memset(ans,0,sizeof(ans));
    for (pii p : v) {
        if (p.t == 0) {
            update(w[p.ix], t[p.ix]);
            ans[p.ix] -= query(w[p.ix]-1);
        } else {
            ans[p.ix] += query(w[p.ix]-1);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
}

