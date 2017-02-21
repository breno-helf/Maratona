//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, l, r;
int esp[112];
int h;
int main () {
    cin >> n >> l >> r;
    ll num = n;
    h = 0;
    while (n > 1) {
	h++;
	n /= 2;
    }
    
    for (int i = h; i > 0; i--) {
	esp[i] = num % 2;
	num /= 2;
    }
    esp[0] = num;
    int resp = 0;
    for (ll i = l; i <= r; i++) {
	int k = __builtin_ctzll(i);	
	debug ("idx %lld >> %lld -- %d\n", i, k, esp[k]);
	resp += esp[k];
    }
	
    cout << resp << '\n';
}

