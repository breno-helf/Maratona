//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 51234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const int guys = 500;

struct node {
    int id, val, nxt;
    node(int ID = 0, int VAL = 0, int NXT = 0):
	id(ID), val(VAL), nxt(NXT) {}
    
    bool operator < (const node ot) const {
	if (val != ot.val) return val < ot.val;
	return id < ot.id;
    }
};

int n, start, x;
vector<node> known;
map<int, node> M;
int used = 0;

node query(int i) {
    used++;
    int v, nxt;
    cout << "? " << i << '\n';
    fflush(stdout);
    cin >> v >> nxt;

    if (v == -1 && nxt == -1) exit(0);
    M[i] = node(i, v, nxt);
    
    return node(i, v, nxt);
}


int main() {
    srand(time(NULL));
    cin >> n >> start >> x;
    vector<int> id;
    for (int i = 1; i <= n; i++) {
	if (start != i)
	    id.pb(i);
    }

    random_shuffle(id.begin(), id.end());

    known.pb(query(start));
    
    for (int i = 0; i < min(n - 1, guys); i++) {
	known.pb(query(id[i]));
    }

    sort(known.begin(), known.end());
    int tam = known.size();
    node resp = M[start];
    for (int i = 0; i < tam; i++) {
	if (known[i].val < x)
	    resp = known[i];
    }

    M[-1] = node(-1, -1, -1);
    
    while (used < 1999) {
	int nxt = resp.nxt;
	if (nxt == -1) break;
	if (M.find(nxt) == M.end()) query(nxt);
	if (M[nxt].val < x) resp = M[nxt];
	else break;
    }

    if (resp.val >= x)
	cout << "! " << resp.val << '\n';
    else
	cout << "! " << M[resp.nxt].val << '\n';

    fflush(stdout);
 }

