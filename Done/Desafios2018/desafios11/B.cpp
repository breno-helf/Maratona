#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 10;

int n;
int c;
string r, s;
int dp[MAX][MAX];


int main() {
    // cin.sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    cin >> c;
    while (c--) {
        cin >> n;
        cin >> s >> r;
        bool ok = false;

        dp[n][n] = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (abs(s[i] - r[j]) <= 1) dp[i][j] = dp[i + 1][j + 1] + 1;
                if (dp[i][j] >= ((n + 1) / 2)) ok = true;
            }
        }
        
        if (ok) {
            cout << "POSITIVE" << '\n';
        } else cout << "NEGATIVE" << '\n';

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) dp[i][j] = 0;
    }

    return 0;
}
