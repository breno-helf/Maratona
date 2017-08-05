//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
int p[MAX];
int x[MAX], l[MAX], r[MAX];
int bit[MAX];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
	scanf("%d", p + i);
    }
        
    for (int i = 0; i < m; i++) {	
	scanf("%d%d%d", l + i, r + i, x + i);
	int esq, dir;
	esq = dir = 0;
	for (int j = l[i]; j < x[i]; j++)
	    if (p[j] > p[x[i]]) esq++;
	for (int j = x[i] + 1; j <= r[i]; j++)
	    if (p[j] < p[x[i]]) dir++;

	if (esq == dir) puts("Yes");
	else puts("No");
    }
    return 0;
}

