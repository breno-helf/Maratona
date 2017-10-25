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

int n;

int main() {
    scanf("%d", &n);
    printf("%d\n", n + n / 2);
    for (int i = 1; i <= n; i++) {
	if (i % 2 == 0) printf("%d ", i);
    }
    for (int i = 1; i <= n; i++) {
	if (i % 2 == 1) printf("%d ", i);
    }
    for (int i = 1; i <= n; i++) {
	if (i % 2 == 0) printf("%d ", i);
    }
    printf("\n");
}

