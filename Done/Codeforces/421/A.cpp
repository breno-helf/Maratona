//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int c, v0, v1, a, l;

int main() {
    scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);

    int cur = v0, v = v0, d = 1;

    while (cur < c) {
	v = min(v + a, v1);
	cur += v - l;
	d++;
    }
    printf("%d\n", d);
}

