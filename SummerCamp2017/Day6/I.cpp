//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, t;
pll cord[MAX], ini[MAX];
set <pll> ordX, ordY; 
char dir[MAX];
map <pll, int> idx;
ll wh[MAX];
int seen[112][MAX];

pll getPos (ll i, ll T) {
    if (dir[i] == 'U')
	return mp(cord[i].first, cord[i].second + (T - wh[i]));
    else if (dir[i] == 'D')
	return mp(cord[i].first, cord[i].second - (T - wh[i]));
    else if (dir[i] == 'R')
	return mp(cord[i].first + (T - wh[i]), cord[i].second);
    else
	return mp(cord[i].first - (T - wh[i]), cord[i].second);
    assert(false);
}

ll prox (ll i, ll T) {
    set<pll>::iterator ptr;
    
    if (dir[i] == 'U') {
	ptr = ordX.upper_bound (getPos(i, T));
	if (ptr == ordX.end())
	    return -1;
	ll j = idx[*ptr];
	if (cord[j].first != cord[i].first)
	    return -1;
	return j;
    }
    else if(dir[i] == 'D') {
	ptr = ordX.lower_bound (getPos(i, T));		
	if (ptr == ordX.begin())
	    return -1;
	ptr = prev(ptr);

	ll j = idx[*ptr];
	if (cord[j].first != cord[i].first)
	    return -1;
	return j;
    }
    else if (dir[i] == 'R') {
	pll nxt = getPos(i, T);
	nxt = mp(nxt.second, nxt.first);
	ptr = ordY.upper_bound (nxt);
	if (ptr == ordY.end())
	    return -1;

	ll j = idx[mp(ptr->second, ptr->first)];
	if (cord[j].second != cord[i].second)
	    return -1;
	return j;
    }
    else if (dir[i] == 'L') {
	pll nxt = getPos(i, T);
	nxt = mp(nxt.second, nxt.first);
	ptr = ordY.lower_bound (nxt);
	if (ptr == ordY.begin())
	    return -1;
	ptr = prev(ptr);

	ll j = idx[mp(ptr->second, ptr->first)];
	if(cord[j].second != cord[i].second)
	    return -1;
	return j;
    }
    assert(false);
}

ll dist (pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main () {
    
    scanf ("%lld %lld", &n, &t);
    for (int  i = 1; i <= n; i++) {
	scanf ("%lld %lld %c", &cord[i].first, &cord[i].second, &dir[i]);
	idx[cord[i]] = i;
	ordX.insert (mp(cord[i].first, cord[i].second));
	ordY.insert (mp(cord[i].second, cord[i].first));
	wh[i] = t;
    }
    
    set <pair<ll, pll> > fila;
    wh[1] = 0;
    int x = prox(1, 0);
    if(x != -1)
	fila.insert (mp(dist(cord[1], cord[x]), mp(1, x)));
    
    while (!fila.empty()) {
	ll tempo = fila.begin()->first;
	ll atual = fila.begin()->second.first;
	ll nxt = fila.begin()->second.second;
	fila.erase (fila.begin());

	debug("Analisys %lld hit %lld\n", atual, nxt);
	
	if (seen[dir[atual]][nxt]) continue;
	seen[dir[atual]][nxt] = 1;
	
	wh[nxt] = min(wh[nxt], tempo);

	ll j = prox(atual, tempo);

	debug("depois %lld\n", j);
	
	if (j != -1) {
	    pair<ll, pll> ins = mp(tempo, mp(atual, nxt));
	    ins.second.second = j;
	    ins.first += dist(getPos(atual, ins.first), cord[j]);

	    debug("Acertei %lld em %lld\n", j, ins.first);
	    
	    if (ins.first < t)
		fila.insert(ins);
	}

	j = prox(nxt, tempo);

	debug("e entao %lld\n", j);

	
	if(j != -1) {
	    pair<ll, pll> ins = mp(tempo, mp(atual, nxt));
	    ins.second.first = nxt;
	    ins.second.second = j;
	    ins.first += dist(getPos(nxt, ins.first), cord[j]);

	    if (ins.first < t)
		fila.insert(ins);
	}
    }
    for (int i = 1; i <= n; i++) {
	pll p = getPos(i, t);
	printf("%lld %lld\n", p.first, p.second);
    }
}
