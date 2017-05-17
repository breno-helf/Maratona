// Distribuited Code Jam Header
// Do not forget to include the problem header!
#include <message.h>
#include <bits/stdc++.h>
#include "query_of_death.h" 
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair
#define MASTER_NODE 0

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;



int main () {
    ll C = NumberOfNodes();
    ll ID = MyNodeId();
    ll N = GetLength();
    
    if (ID == 1) {
	ll broken = -1;
	for (int i = 0; i < N; i++) {
	    ll last = -1;
	    for (int j = 0; j < 100; j++) {
		if (last == -1) {
		    last = GetValue(i);
		} else if (GetValue(i) != last) {
		    broken = i;
		    break;
		}
	    }
	    if (broken != -1) break;
	}
	PutLL(0, broken);
	Send(0);
    }

    if (ID == 0) {
	Receive(1);
	ll broken = GetLL(1);
	ll sum = 0;
	for (int i = 0; i < N; i++) {
	    if (i == broken) continue;
	    sum += GetValue(i);
	}

	sum += GetValue(broken);

	printf ("%lld\n", sum);
    }
	
    return 0;
}

