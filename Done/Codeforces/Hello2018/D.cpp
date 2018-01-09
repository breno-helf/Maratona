//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct prob {
    int a, t, id;
    prob(int A, int TT, int ID):
	a(A), t(TT), id(ID) {}

    bool operator < (const prob ot) const {
	if (t == ot.t) return id < ot.id;
	return t < ot.t;
    }
};

int n, T, a[MAX], t[MAX];

int dp[MAX];

set<prob> S, resp;
vector<prob> num[MAX], v;
int mx;

int main() {
    scanf("%d %d", &n, &T);

    for (int i = 1; i <= n; i++) {
	scanf("%d %d", a + i, t + i);
	prob cur = prob(a[i], t[i], i);
	S.insert(cur);
	v.pb(cur);
	num[a[i]].pb(cur);
    }
    sort(v.begin(), v.end());
    
    int temp = 0;
    for (int i = 1; i <= n; i++) {

	for (auto P : num[i - 1]) {
	    //debug("(%d) ==> Deletando %d\n", i, P.id);
	    if (S.find(P) != S.end()) S.erase(P);
	    if (resp.find(P) != resp.end()) {
		temp -= P.t;
		resp.erase(P);
	    }
	}

	set<prob>::iterator it = S.begin();
	int tam = resp.size();
	while (it != S.end() && tam < i) {
	    resp.insert(*it);
	    temp += it->t;
	    S.erase(it);
	    tam++;
	    it = S.begin();
	}

	//debug("--> %d %d\n", tam, temp);
	if (temp <= T)
	    mx = max(mx, tam);
	
	// if (tam > mx && temp <= T) {
	//     mx = tam;
	    
	//     //debug("(%d) --> %d %d\n", i, mx, temp);
	//     final.clear();
	//     for (auto P : resp)
	// 	final.pb(P);
	// }	
    }

    
    printf("%d\n%d\n", mx, mx);
    int cur = 1;
    
    for (int i = 0; i < n; i++) {
	if (cur <= mx && mx <= v[i].a) {
	    printf("%d ", v[i].id);
	    cur++;
	}
    }
    
    printf("\n");
}
