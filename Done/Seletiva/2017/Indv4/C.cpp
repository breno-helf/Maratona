#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const ll  INF = (ll)1e15;
const ll  MOD = 1000000007;

ll dp[MAX][MAX * MAX];
ll n, d, t;
ll h[MAX], cost[MAX][MAX * MAX];
vector<ll> p[MAX];

ll solve (int i, int j) {
    if (i == n) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    
    //debug ("Testando %d com altura %lld\n", i, p[i][j]);
    
    ll resp = INF;

    int id = lower_bound(p[i + 1].begin(), p[i + 1].end(), p[i][j] - d) - p[i + 1].begin();
    int fim = upper_bound(p[i + 1].begin(), p[i + 1].end(), p[i][j] + d) - p[i + 1].begin();
    //debug ("--> Chamando proximo partir de %d (%lld)\n\n", id, p[i + 1][id]); 
    for (int k = id; k < fim; k++) {
	    //debug (">>> Chamei %d (custou %lld)\n", i + 1, cost[i + 1][k]);
	resp = min(resp, solve (i + 1, k) + cost[i + 1][k]);
    }

    return dp[i][j] = resp;    
}


int main () {
    scanf ("%lld", &t);
    while (t--) {
	scanf ("%lld %lld", &n, &d);

	//memset(dp, ((ll)-1), sizeof(dp));

	ll menor = INF;
	ll maior = -1;
	
	for (int i = 1; i <= n; i++) {
	    p[i].clear();
	    scanf ("%lld", h + i);
	    menor = min(menor, h[i]);
	    maior = max(maior, h[i]);
	}
	p[1].pb(h[1]);
	cost[1][0] = 0;
	dp[1][0] = 0;
	p[n].pb(h[n]);
	cost[n][0] = 0;
	dp[n][0] = INF;
	for (int i = 2; i < n; i++) {
	    vector<ll> cur;
	    for (int j = 1; j <= n; j++) {
		for (ll k = 0; k <= abs(i - j); k++) {
		    if (h[j] - k * d >= menor) {
			cur.pb(h[j] - k * d);
		    }
		    if (h[j] + k  * d <= maior)
			cur.pb(h[j] + k * d);
		}
	    }

	    sort (cur.begin(), cur.end());
	    ll last = -1;
	    for (ll e : cur) {
		if (e == last) continue;
		cost[i][p[i].size()] = abs(h[i] - e);
		dp[i][p[i].size()] = INF;
		p[i].pb(e);
		last = e;
	    }
	}	    
	
	for (int i = 2; i <= n; i++) {
	    int tam = p[i].size();
	    int ini, fim, sz;
	    multiset<ll> V;
	    ini = fim = lower_bound(p[i - 1].begin(), p[i - 1].end(), p[i][0] - d) - p[i - 1].begin();
	    sz = p[i - 1].size();
	    debug ("--> Analisando %d\n", i);
	    for (int j = 0; j < tam; j++) {		
		while (fim < sz && abs(p[i - 1][fim] - p[i][j]) <= d) {
		    V.insert(dp[i - 1][fim++]);
		    
		}
		debug ("%d %d %d\n", ini, fim, sz);
				
		while (ini < fim && abs(p[i - 1][ini] - p[i][j]) > d) {
		    V.erase(V.find(dp[i - 1][ini++]));		    
		}
		
		ll last;	
		
		if (!V.empty()) last = *(V.begin());
		else last = INF;

		debug ("Last eh %lld quando eu sou %lld\n", last, p[i][j]);
		
		dp[i][j] = last + cost[i][j];
	    }
	}
	

	ll ans = dp[n][0];

	if (ans >= (ll)INF)
	    printf ("impossible\n");
	else 
	    printf ("%lld\n", ans);
    }
    return 0;
}
