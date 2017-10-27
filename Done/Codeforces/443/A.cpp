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

int n, s[MAX], d[MAX];
int cur;

int main() {
    scanf("%d", &n);
    cur = 1;
    for (int i = 0; i < n; i++) {
	scanf("%d %d", s + i, d + i);
	int k = max((cur - s[i] + d[i] - 1) / d[i], 0);
	cur = max(s[i] + k * d[i] + 1, cur + 1);
	assert(cur == (s[i] + k * d[i] + 1));
    }

    printf("%d\n", cur - 1);
}

