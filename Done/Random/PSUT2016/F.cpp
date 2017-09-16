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

int n, m, q;
int qtd[MAX];
int st[MAX];
set<int> pos;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
	scanf("%d", st + i);
	qtd[st[i]]++;
    }

    for (int i = 1; i <= m; i++) if (qtd[i] == 0) pos.insert(i);

    for (int i = 0; i < q; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	qtd[st[a]]--;
	if (qtd[st[a]] == 0) pos.insert(st[a]);
	st[a] = b;
	qtd[st[a]]++;
	if (qtd[st[a]] == 1) pos.erase(st[a]);

	printf("%d\n", (int)pos.size());
    }
    return 0;
}

