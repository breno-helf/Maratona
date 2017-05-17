// Distribuited Code Jam Header
// Do not forget to include the problem header!
#include <message.h>
#include <bits/stdc++.h>
#include "pancakes.h" 
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair
#define MASTER_NODE 0

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int main () {
    ll C = NumberOfNodes();
    ll ID = MyNodeId();
    ll N = GetStackSize();
    ll D = GetNumDiners();

    if (N < C) {
	if (ID == MASTER_NODE) {
	    ll last = -1, resp = 0;
	    for (ll i = 0; i < N; i++) {
		ll cur = GetStackItem(i);
		if (cur < last) {
		    resp++;
		}
		last = cur;
	    }
	    printf ("%lld\n", resp + 1);
	    return 0;
	} else return 0;
    }
    
    
    ll L = (ID * N) / C, R = ((ID + 1) * N) / C;
    ll last = -1, resp = 0;
    for (ll i = L; i < R; i++) {
	ll cur = GetStackItem(i);
	if (cur < last) {
	    resp++;
	}
	last = cur;
    }
    resp++;

    if (ID != (C - 1)) {
	PutLL(ID + 1, last); 
	Send(ID + 1);
    }

    if (ID != MASTER_NODE) {
	Receive(ID - 1);
	int U = GetLL(ID - 1);
	if (U <= GetStackItem(L)) {
	    resp--;
	}
	PutLL(MASTER_NODE, resp);
	Send(MASTER_NODE);
    }
    
    if (ID == MASTER_NODE) {
	
	for (int node = 1; node < C; node++) {
	    Receive(node);
	    int MSG = GetLL(node);	    
	    resp += MSG;
	}
	printf ("%lld\n", resp);
    }
    resp;
}

