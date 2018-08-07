//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cost = INF;
    for (int K = -100; K <= 100; K++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            cur += (K - a[j]) * (K - a[j]);
        }
        cost = min(cost, cur);
    }

    cout << cost << endl;
}


