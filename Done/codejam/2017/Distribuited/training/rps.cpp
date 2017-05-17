#include <message.h>
#include <stdio.h>
#include <algorithm>
#include "rps.h"
using namespace std;

#define MASTER_NODE 0
#define DONE -1
#define pb push_back


typedef long long ll;

long long INF = (long long)1e18 + 10;

ll win (ll a, ll b) {
    char A = GetFavoriteMove(a);
    char B = GetFavoriteMove(b);
    if (A == B) return a;
    if (A == 'R') {
	if (B == 'S') return a;
	else return b;
    } else if (A == 'S') {
	if (B == 'P') return a;
	else return b;
    } else {
	if (B == 'R') return a;
	else return b;	
    }
}

int main() {
    long long N = GetN();
    long long nodes = NumberOfNodes();
    long long ID = MyNodeId();
  
    if (N <= 22) {
	if (ID == MASTER_NODE) {
	    vector<ll> V;
	    for (int i = 0; i < (1<<N); i++)
		V.pb(i);
	    while (N) {
		vector<ll> nxt;
		for (int i = 0; i < (1<<N); i += 2) {
		    nxt.pb(win(V[i], V[i + 1]));		  
		}
		V = nxt;
		N--;
	    }
	    printf ("%lld\n", V[0]);
	}
    } else {
	if (ID >= (1<<(N - 22)))
	    return 0;
	long long ini = (1<<22) * ID;
	long long fim = (1<<22) * (ID + 1);
	long long S = 22;

	vector<ll> V;

	for (int i = ini; i < fim; i++)
	    V.pb(i);
	while (S) {
	    vector<ll> nxt;
	    for (int i = 0; i < (1<<S); i += 2) {
		nxt.pb(win(V[i], V[i + 1]));		  
	    }
	    V = nxt;
	    S--;
	}

	ll W = V[0];

	if (ID == MASTER_NODE) {
	    vector<ll> cur;
	    int tam = (1<<(N - 22));
	    cur.pb(W);
	  
	    for (int i = 1; i < tam; i++) {
		Receive(i);
		ll add = GetLL(i);
		cur.pb(add);
	    }

	    S = N - 22;
	  
	    while (S) {
		vector<ll> nxt;
		for (int i = 0; i < (1<<S); i += 2) {
		    nxt.pb(win(cur[i], cur[i + 1]));		  
		}
		cur = nxt;
		S--;
	    }

	    printf ("%lld\n", cur[0]);
	  
	} else {
	    PutLL(MASTER_NODE, W);
	    Send(MASTER_NODE);
	}
      
    }
    
    return 0;
}
