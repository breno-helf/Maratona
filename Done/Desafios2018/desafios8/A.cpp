#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e3 + 10;
const int INF = 1e9 + 10;
int n;
ll b;

map<string, int> M;
vector<pii> v[MAX];
int pt[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> b;
        int c = 1;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            pt[i] = 0;
        }
        M.clear();
        
        for (int i = 1; i <= n; i++) {
            string s, r;
            ll p, q;
            cin >> s >> r >> p >> q;
            if (M.find(s) == M.end()) M[s] = c++;
            v[M[s]].push_back(pii(p, q));
        }
        
        set<pii> S;
        ll cost = 0;
        int qual = INF;
        for (int i = 1; i < c; i++) {
            sort(v[i].begin(), v[i].end());
            S.insert(pii(v[i][0].second, i));
            cost += v[i][0].first;
            qual = min(qual, v[i][0].second);
        }

        while (cost <= b) {
            pii cur = *S.begin();
            int i = cur.second;
            int q = cur.first;
            S.erase(S.begin());

            cost -= v[i][pt[i]].first;
            pt[i]++;
            
            while (pt[i] < v[i].size() && v[i][pt[i]].second < q) pt[i]++;
            if (pt[i] == v[i].size()) break;

            cost += v[i][pt[i]].first;
            S.insert(pii(v[i][pt[i]].second, i));
            
            if (cost <= b)
                qual = max(qual, S.begin()->first); 
        }

        printf("%d\n", qual);
    }
        
}
