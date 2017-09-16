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

int n;
ll val[] = {1, 5, 10, 20, 50};
ll qtd[5];

void paga(ll num) {
    for (int j = 4; j >= 0; j--) {
	while (val[j] <= num && qtd[j] > 0) {
	    //debug("==> Usando %lld\n", val[j]);
	    num -= val[j];
	    qtd[j]--;
	}
    }
    if (num > 0) {
	//debug("--> %lld\n", num);
	puts("no");
	exit(0);
    }
    
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	ll k, f[5], sum = 0;
	scanf("%lld", &k);
	for (int j = 0; j < 5; j++) {
	    scanf("%lld", f + j);
	    sum += val[j] * f[j];
	    qtd[j] += f[j];
	}
	ll dif = sum - k;
	//debug("--> Pagando %lld\n", dif);
	paga(dif);	
    }
    puts("yes");
    return 0;
}


