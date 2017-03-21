#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e6 + 2;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
char s[MAX];
map<ll, int> M;

int main () {
    scanf("%d%d", &n, &k);
    scanf(" %s", s);
    ll sum = 0;
    int resp = 0;
    for (int i = 0; i < n; i++) {
	if (s[i] == 'O') sum++;
	else sum -= k;

	if (!sum) resp = i + 1;
	else if (M.find(sum) != M.end()) {
	    resp = (i - M[sum] > resp) ? i - M[sum] : resp;
	}
	else {
	    M[sum] = i;
	}
    }
    
    printf("%d\n", resp);
    return 0;
}

