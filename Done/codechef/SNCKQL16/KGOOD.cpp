#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s;
        cin >> k;
        int count[500];
        memset (count, 0, sizeof (count));
        int tam = s.size();
        for (int i = 0; i < tam; i++) {
            count[s[i]]++;
        }
        int ans = 1000000000;
        for (char c = 'a'; c <= 'z'; c++) {
            if (!count[c]) continue;
            int base = count[c];
            for (int i = 0; i <= k; i++) {
                int tans = 0;
                for (char d = 'a'; d <= 'z'; d++) {
                    if (!count[d]) continue;
                    if (count[d] > base + i || count[d] < base - k + i) {
                        if (count[d] > base) tans += count[d] - base - i;
                        else tans += count[d];
                    }
                }
                ans = min (ans, tans);
            }
        }
        cout << ans << endl;
    }
}
