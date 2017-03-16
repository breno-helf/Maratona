//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
char s[MAX];
ll abre[MAX], fecha[MAX];
ll dp[MAX];
ll resp;
ll fat[MAX], inv[MAX];
int main () {
    fat[0] = 1;
    for (ll i = 1; i < MAX; i++)
	fat[i] = (fat[i - 1] * i) % MOD;
    inv[MAX - 1] = 232193893;
    for (ll i = MAX - 2; i >= 0; i--)
	inv[i] = (inv[i + 1] * (i + 1)) % MOD;

    scanf(" %s", s);
    n = strlen(s);
    abre[0] = 0;
    int ini = INF;
    for (int i = 0; i < n; i++) {
	if (i) abre[i] = abre[i - 1];
	if (s[i] == '(') {
	    abre[i]++;
	}
    }
    fecha[n - 1] = (s[n - 1] == ')') ? 1 : 0;
    for (int i = n - 2; i >= 0; i--) {
	fecha[i] = fecha[i + 1];
	if (s[i] == ')') fecha[i]++;
    }
    
    for (int i = 0; i < n; i++) {
	debug ("%lld %lld\n", abre[i], fecha[i]);
	debug ("%lld %lld %lld\n", fat[abre[i] + fecha[i] - 1], inv[fecha[i] - 1], inv[abre[i]]);
	ll sum = (fat[abre[i] + fecha[i] - 1] * inv[fecha[i] - 1]) % MOD;
	sum *= inv[abre[i]];
	sum %= MOD;
	if (s[i] == '(')
	    resp += sum;
	resp %= MOD;
    }
    printf("%lld\n", resp);
}
