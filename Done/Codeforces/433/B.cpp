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

int n, k;

int x, y;

int main() {
    scanf("%d %d", &n, &k);

    if (k == 0 || k == n) {
	puts("0 0");
	return 0;
    }
    
    x = 1;
    
    if (k < (n + 2) / 3) {
	y = 2 * k;
    } else {
	y = n - k;
    }
    
    printf("%d %d\n", x, y);
}

