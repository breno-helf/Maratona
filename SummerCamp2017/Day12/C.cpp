#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll,ll,ll> t3;
const int MAXN = 1e6+10;

ll w[MAXN];
int at[MAXN];
int to[MAXN];
int best = -1;
bool ok[MAXN];
vector<t3> v;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
        if (best == -1 || w[i] < w[best])
            best = i;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &at[i]);
    }

    for (int i = 1,a; i <= n; i++) {
        scanf("%d", &a);
        to[a] = at[i];
    } 

    for (int i = 1,cur; i <= n; i++) {
        if (ok[i]) continue;

        cur = i;
        ll cycSize = 0, cycSum = 0;
        int cycBest = -1;
        while (true) {
            ok[cur] = true;

            cycSize++;
            cycSum += w[cur];
            if (cycBest == -1 || w[cur] < w[cycBest])
                cycBest = cur;

            if (ok[to[cur]]) break;
            else cur = to[cur];
        }

        v.push_back(t3(cycSize, cycSum-w[cycBest], w[cycBest]));
    }

    ll ans = 0;
    for (t3 p : v) {
        if (get<0>(p) <= 1) continue;
        ans += min(get<2>(p) * (get<0>(p) - 1LL) + get<1>(p),
                   w[best] * (get<0>(p) + 1LL) + get<1>(p) + 2*get<2>(p));
    }
    printf("%lld\n", ans);
}
