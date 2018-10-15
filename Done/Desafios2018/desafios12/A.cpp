#include<bits/stdc++.h>
using namespace std;

const int MAX = 5123;

int n, a[MAX];
int used[MAX];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = i; j < n; j++) {
            if (a[j] > a[i] && !used[j]) {
                used[j] = 1;
                ok = true;
                break;
            }
        }

        if (!ok) ans++;
    }
    cout << ans << '\n';
}


