//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 13231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int k;
ll n;

int main() {
    scanf("%d", &k);
    n = (1LL<<(k + 1)) - 1LL;

    printf("%lld\n", n);
}

