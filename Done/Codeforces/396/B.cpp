//If you are trying to hack me I wish you can get it, Good Luck :D
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

int n, a[MAX];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", a + i);
    sort(a, a + n);
    bool ok = false;

    for (int i = 1; i < n - 1; i++) {
	if ((a[i - 1] + a[i]) > a[i + 1]) ok = true;
    }    
    
    if (ok) puts("YES");
    else puts("NO");
}

