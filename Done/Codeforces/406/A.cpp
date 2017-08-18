#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 21;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll A, B, C, D;
set<ll> S;
int main () {
    scanf("%lld%lld%lld%lld", &A, &B, &C, &D);

    ll resp = -1;

    for (ll i = 0; i <= 100000; i++) {
	S.insert(B + A * i);
    }
                   
    
    for (ll i = 0; i <= 100000; i++) {
	if (S.find(D + C * i) != S.end()) {
	    resp = D + C * i;
	    //printf("%lld %lld\n", i, (D + C * i - B) / A);
	    break;
	}
	    
    }
    
    printf("%lld\n", resp);
    
    return 0;
}
