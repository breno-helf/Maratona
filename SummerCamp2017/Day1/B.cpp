#include <bits/stdc++.h>
using namespace std;

int n, dist;
// sl: faced left, sr: faced right
set<int> sl, sr;
int x;

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0,a,b; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (b == 0) {
            sr.insert(a);
        } else {
            sl.insert(a);
        }
    }

    bool goingLeft = true;
    int ans = 0;
    int cnt = n;
    while (true) {
        //printf("x %d ans %d cnt %d goingLeft %d sl %d sr %d\n", x, ans, cnt, goingLeft, sl.size(), sr.size());
        if (cnt == 0 && !goingLeft)
            break;
        if (goingLeft) {
            auto it = sr.lower_bound(x);
            if (it == sr.begin() || sr.empty()) {
                ans++;
                x = 0;
            } else {
                cnt--;
                it = prev(it);
                x = *it;
                sr.erase(it);
            }
            goingLeft = false;
        } else {
            auto it = sl.upper_bound(x);
            if (it == sl.end() || sl.empty()) {
                printf("-1\n");
                return 0;
            } else {
                cnt--;
                x = *it;
                sl.erase(it);
            }
            goingLeft = true;
        }
    }
    printf("%d\n", ans);
}

