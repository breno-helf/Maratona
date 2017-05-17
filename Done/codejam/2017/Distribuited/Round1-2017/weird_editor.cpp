// Distribuited Code Jam Header
// Do not forget to include the problem header!
#include <message.h>
#include <bits/stdc++.h>
#include "weird_editor.h" 
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair
#define MASTER_NODE 0

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1231321;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll fexp (ll a, ll e) {
    ll pow = a, ret = 1;
    
    for (int i = 0; i < 60; i++) {
	if (e & (1LL<<i)) {
	    ret *= pow;
	    ret %= MOD;
	}
	pow *= pow;
	pow %= MOD;
    }
    
    return ret;
}

int main () {
    ll C = NumberOfNodes();
    ll ID = MyNodeId();
    ll N = GetNumberLength();

    if (true) { // N < C
	if (ID == MASTER_NODE) {
	    ll P = 1;
	    ll last = 0;
	    ll sum = 0;
	    for (ll i = N - 1; i >= 0; i--) {
		ll cur = GetDigit(i);
		if (cur != 0 && cur >= last) {
		    sum = (sum + (cur * P) % MOD) % MOD;
		    P = (P * 10) % MOD;
		    last = cur;
		} else {
		    sum = (sum * 10) % MOD;
		    P = (P * 10) % MOD;
		}
	    }
	    printf ("%lld\n", sum);	    
	    return 0;
	} else return 0;
    }
    
    
    ll L = (ID * N) / C, R = ((ID + 1) * N) / C;
    
    ll P = 1;
    ll last = 0;
    ll sum = 0;
    ll Q = 0;
    for (ll i = R - 1; i >= L; i--) {
	ll cur = GetDigit(i);
	if (cur != 0 && cur >= last) {
	    sum = (sum + (cur * P) % MOD) % MOD;
	    P = (P * 10) % MOD;
	    last = cur;
	    Q++;
	} else {
	    sum = (sum * 10) % MOD;
	    P = (P * 10) % MOD;
	}
    }
        
    if (ID != (C - 1)) {
	Receive(ID + 1);

	ll L2 = ((ID + 1) * N) / C, R2 = ((ID + 2) * N) / C;
	ll k = R2 - L2;
	
	ll S2 = GetLL(ID + 1);
	ll Last2 = GetLL(ID + 1);

	if (Last2 > last) {
	    sum = (S2 * P) % MOD;
	    last = Last2;
	} else {
	    sum = ((S2 * (fexp(10, Q))) % MOD  + (sum * fexp(10, k)) % MOD) % MOD;
	}

	if (ID != MASTER_NODE) {
	    PutLL(ID - 1, sum);
	    PutLL(ID - 1, last);
	    Send(ID - 1);
	}
    } else {
	PutLL(ID - 1, sum);
	PutLL(ID - 1, last);
	Send(ID - 1);
    }

    if (ID == MASTER_NODE) {
	printf ("%lld\n", sum);
    }
    
    return 0;
}

