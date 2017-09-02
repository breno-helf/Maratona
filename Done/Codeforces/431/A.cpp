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

int n;
int a[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	scanf("%d", a + i);

    
    
    if (a[1] % 2 == 0 || a[n] % 2 == 0) {
	puts("No");
	return 0;
    }

    if (n % 2 == 1) {
	puts("Yes");
    } else {
	puts("No");
    }
    return 0;
}

