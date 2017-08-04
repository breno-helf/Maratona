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
int b[MAX];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", a + i);
    
    bool ok = true;
    
    for (int i = 1; i < n; i++) {
	if (a[i] > a[i - 1]) {
	    b[i] = 0;
	} else if (a[i] == a[i - 1]) {
	    b[i] = 1;
	} else {
	    b[i] = 2;
	}
    }

    int cur = 0;
    
    for (int i = 1; i < n; i++) {
	if (b[i] < cur) ok = false;
	cur = b[i];
    }
    
    if (ok) puts("YES");
    else puts("NO");
    
}

