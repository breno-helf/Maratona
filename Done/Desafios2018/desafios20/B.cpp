#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    int ans = 0;
    set<int> P;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int G = 10000, S = 0;

        for (int j = 0; j < m; j++) {
            if (s[j] == 'G') G = j;
            if (s[j] == 'S') S = j;                                
        }

        if (G > S) {
            cout << -1 << '\n';
            return 0;
        }

        P.insert(S - G);
    }
    
    int cur = 0;

    while (!P.empty() && (*P.begin() - cur) >= 0) {
        ans++;
        cur = *P.begin();
        P.erase(P.begin());
    }
    
    cout << ans << '\n';
}
