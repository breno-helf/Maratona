#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int s[2 * MAX];

int n;
int nxt[2 * MAX];
int prv[2 * MAX];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 2 * MAX; i++) {
	nxt[i] = i + 1;
	prv[i] = i - 1;
    }
    
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
	string cur;
	cin >> cur;
	int tam = cur.size();
	int qtd;
	cin >> qtd;
	for (int k = 0; k < qtd; k++) {
	    int a;
	    cin >> a;
	    for (int j = a; j < a + tam; j++) {
		s[j - 1] = cur[j - a];
		int P = nxt[j] - 1;
		nxt[j] = nxt[a + tam - 1];
		prv[j] = prv[a];
		m = max(m, j);
		j = P;
	    }
	}
    }

    for (int i = 0; i < m; i++) {
	//debug ("%d -- %d\n", nxt[i], prv[i]);
	if (s[i] == 0) s[i] = 'a';
	char c = s[i];
	cout << c;
    }
    cout << '\n';
}


