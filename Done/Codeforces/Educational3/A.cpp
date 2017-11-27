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

int a[MAX], m, n;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf("%d", a + i);
    }

    sort(a, a + n);
    reverse(a, a + n);
    int resp = 0, tot = 0;
    while (tot < m) {
	tot += a[resp];
	resp++;
    }

    printf("%d\n", resp);
}

