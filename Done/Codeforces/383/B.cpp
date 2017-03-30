#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, x;
int a[MAX];
map<int, ll> M;
ll resp = 0;
int main () {
    scanf ("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
	scanf ("%d", a + i);

    for (int i = n - 1; i >= 0; i--) {
	int k = x ^ a[i];
	resp += M[k];
	M[a[i]]++;
    }

    printf("%lld\n", resp);
}

