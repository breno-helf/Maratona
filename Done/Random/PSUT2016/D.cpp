//If you are trying to hack me I wish you can get it, Good Luck :D.
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

int n, q;
set<pii> S;
int qtd[MAX];

int main() {
    // cin.sync_with_stdio(false);
    // cin.tie(0);
    
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
	int a;
	cin >> a;
	qtd[i] = a;
	S.insert(pii(a, i));
    }


		
    for (int i = 0; i < q; i++) {
	string s;
	int num;
	cin >> s >> num;

	//cout << s << ' ' << num << '\n';
	
	if (s == "in") {
	    auto it = S.lower_bound(pii(num, 0));
	    if (it == S.end()) cout << -1 << '\n';
	    else {
		//debug("aqui? %d %d\n", it->first, it->second);
		cout << it->second << '\n';
		S.erase(it);
	    }
	} else {
	    S.insert(pii(qtd[num], num));
	}
    }
    return 0;
}



