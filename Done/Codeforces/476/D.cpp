//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int l, w;
int a[MAX];
int DP[MAX];

bool canJump(int K) {
    DP[0] = K;
    debug("===========\n%d ", DP[0]);
    for (int i = 1; i <= w + 1; i++) {
        DP[i] = DP[i - 1];
        if (i - l > 0) {
            DP[i] -= DP[i - l - 1];
        }
        if (i > 1) DP[i] += a[i - 1];
        debug("%d ", DP[i]);
    }
    debug("\n\n");
    return DP[w + 1] == K;
}

int main() {
    cin.sync_with_stdio(false);

    cin >> w >> l;
    for (int i = 1; i <= w; i++) cin >> a[i];

    int L = 0, R = INF;
    // while (L < R) {
    //     int M = (R - L) / 2 + L;
    //     if (canJump(M)) {
    //         L = M;
    //     } else {
    //         R = M - 1;
    //     }
    // }

    debug("--> canJump(%d) = %d\n", 3, canJump(3) ? 1 : 0);

    cout << calc() << '\n';
    return 0;
}
