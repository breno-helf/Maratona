//If you are trying to hack me I wish you can get it, Good Luck :D.
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



ll k;
int qtd[30];

ll bb(ll n) {
    ll l = 0, r = 100000;

    while (l < r) {
	ll m = (l + r + 1) / 2;
	ll sum = (m * (m + 1LL)) / 2LL;
	if (sum <= n) l = m;
	else r = m - 1;
    }
    return l;   
}

int main() {
    scanf("%lld", &k);

    for (int i = 0; i < 26; i++) {
	ll num = bb(k);
	k -= ((num) * (num + 1LL)) / 2LL;
	qtd[i] = num + 1;
    }
    
    assert(k == 0);

    for (int i = 0; i < 26; i++) {
	while(qtd[i]--) {
	    printf("%c", i + 'a');
	}
    }
    printf("\n");
}
