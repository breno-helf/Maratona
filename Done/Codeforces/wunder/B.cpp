#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 55;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int n;
int a[MAX][MAX];
int b[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	    scanf("%d", &a[i][j]);

    int q = n;
    
    while(q--) {
	int v = 0;
	int k = 0;
	for (int i = 1; i <= n; i++) {
	    bool ok = true;
	    v = 0;
	    for (int j = 1; j <= n; j++) {
		if (a[i][j] != 0) {
		    if (v == 0) v = a[i][j];
		    else if (a[i][j] != v) {
			ok = false;
			break;
		    }
		}
	    }
	    if (ok && v > 0) {
		k = i;
		break;
	    }
	}

	//debug("-- %d %d\n", k, v);
	
	for (int i = 1; i <= n; i++)
	    a[i][k] = a[k][i] = 0;

	if (b[k] == 0) b[k] = v;
    }

    for (int i = 1; i <= n; i++) {
	if (b[i] == 0) b[i] = n;
	printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}


