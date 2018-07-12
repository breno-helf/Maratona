#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > pii;
#define mp make_pair
int M;

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        vector<pii> R;
        vector<int> G;
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            R.push_back(mp(i, mp(a, b)));
        }
        for (int i = 0; i < M; i++) {
            int q;
            scanf("%d", &q);
            G.push_back(q);
        }

        sort(R.begin(), R.end());
        int best = 0;
        
        do {
            vector<int> cur = G;
            for (auto& form : R) {
                int created = form.first;
                int u = form.second.first;
                int v = form.second.second;

                int q = min(cur[u], cur[v]);
                cur[created] += q;
                cur[u] -= q;
                cur[v] -= q;
                best = max(best, cur[0]);
            }
            
        } while (next_permutation(R.begin(), R.end()));
                
        printf("Case #%d: ", t);
        printf("%d\n", best);
    }
    
    return 0;
}
