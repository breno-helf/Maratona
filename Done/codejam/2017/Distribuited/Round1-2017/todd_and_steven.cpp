// Distribuited Code Jam Header
// Do not forget to include the problem header!
#include <message.h>
#include <bits/stdc++.h>
#include "todd_and_steven.h" 
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair
#define MASTER_NODE 0

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 123123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;



int main () {
    ll C = NumberOfNodes();
    ll ID = MyNodeId();
    ll N = GetToddLength();
    ll M = GetStevenLength();
    ll sum = 0;
    if (ID == MASTER_NODE) {
	ll i = 0, j = 0;
	ll k = 0;
	
	while (i < N && j < M) {
	    ll T = GetToddValue(i);
	    ll S = GetStevenValue(j);
	    if (T > S) {
		sum += S ^ k;
		sum %= MOD;
		k++;
		j++;
	    } else {
		sum += T ^ k;
		sum %= MOD;
		k++;
		i++;
	    }	    
	}

	while (i < N) {
	    ll T = GetToddValue(i);
	    sum += T ^ k;
	    sum %= MOD;
	    k++;
	    i++;
	}

	while (j < M) {
	    ll S = GetStevenValue(j);
	    sum += S ^ k;
	    sum %= MOD;
	    k++;
	    j++;
	}

	printf ("%lld\n", sum);	
	return 0;
    } else return 0;
    return 0;
}

