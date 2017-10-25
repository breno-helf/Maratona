//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
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

struct edge {
    int u, v, w;

    edge(int U, int V, int W):
	u(U), v(V), w(W) {}
};

int n, k;
vector<edge> E;

int main() {
    cin >> n >> k;

    if ((n == 2 || n == 3) && k == 0) {
	cout << -1 << '\n';
	return 0;
    }
    
    int C = 1;
    for (int i = 1; i < n; i++) {
	E.pb(edge(i, i + 1, C++));
    }

    int qtd = n - 1 - k; 
    int no = n;
    //debug("--> %d\n", qtd);

    if (k == 0) qtd--;
    
    for (int i = 0; i < qtd; i++) {
	
	E.pb(edge(1, no--, C++));
    }

    if (k == 0 && n > 1) E.pb(edge(n, 2, C++));

    
    cout << E.size() << '\n';
    for (auto e : E) {
	cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    }
    
}
