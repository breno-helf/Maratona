//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 30;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const int TAM = 312;

struct node {
    int p;
    int nxt[13];
    int sl;
    char c;
    int end;
    bool bad;
} trie[TAM];

int root = 0;
int cnt;
int dp[TAM][12];

void add (const string& s, int num, bool val) {
    int sz = s.size();
    int t = root;
    for (int i = 0; i < sz; i++) {
	char c = s[i];
	int v = c - 'a';
	if (trie[t].nxt[v] == -1) {
	    int son = cnt++;
	    trie[son].c = v;
	    trie[son].p = t;
	    trie[t].nxt[v] = son;
	}
	t = trie[t].nxt[v];

	if (i == (sz - 1)) {
	    if (val) {
		trie[t].end |= (1<<num);
		trie[t].bad = false;
	    }
	    else
		trie[t].bad = true;
	}
    }    
}

void aho () {
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
	int t = Q.front();
	Q.pop();
	int w = trie[t].p;
	debug("%d --> %c   ", t, trie[t].c + 'a');
	if (w != -1) {
	    w = trie[w].sl;
	    while (w != -1 && trie[w].nxt[(int)trie[t].c] == -1) {
		w = trie[w].sl;
	    }
	    trie[t].sl = (w != -1) ? trie[w].nxt[(int)trie[t].c] : root;
	    trie[t].end |= trie[trie[t].sl].end;
	    trie[t].bad |= trie[trie[t].sl].bad;
	}
	debug("%s\n", trie[t].bad ? "BAD" : "--");
	for (char c = 'a'; c <= 'j'; c++)
	    if(trie[t].nxt[c - 'a'] != -1) Q.push(trie[t].nxt[c - 'a']);
    }
    debug("\n\n");
}

int walk (int x, int c) {
    int &res = dp[x][c];
    if (res != -1) return res;
    if (trie[x].nxt[c] != -1)
	res = trie[x].nxt[c];
    else {
	int y = trie[x].sl;
	while (y != -1 && trie[y].nxt[c] == -1)
	    y = trie[y].sl;
	if (trie[y].nxt[c] == -1) res = 0;
	else res = trie[y].nxt[c];	
    }
    return res;
}

string s[MAX], t[MAX];

int dist[TAM][(2<<15) + 10];
pii dad[TAM][(2<<15) + 10];

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < TAM; i++) {
	for (int j = 0; j < 10; j++)
	    trie[i].nxt[j] = -1;
	trie[i].p = -1;
	trie[i].sl = -1;
    }
    memset(dp, -1, sizeof(dp));
    int n, m;
    root = 0;
    trie[root].c = -1;
    cnt = 1;    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
	cin >> s[i];
	add(s[i], i, true);
    }
    for (int i = 0; i < m; i++) {
	cin >> t[i];
	add(t[i], i + n, false);
    }

    for (int i = 0; i < 10; i++) {
	if(trie[root].nxt[i] == -1) {
	    int son = cnt++;
	    trie[son].c = i;
	    trie[son].p = root;
	    trie[root].nxt[i] = son;
	}
    }
    
    aho ();

    int r = 0;
    queue<pii> Q;
    pii st = pii(root, r);
    Q.push(st);
    dist[r][root] = 0;
    dad[r][root] = st;
    string resp = "";
    bool finish = false;
    pii cur = st;
    while (!Q.empty()) {
	pii f = Q.front();
	int no = f.first;
	int bt = f.second;
	
	debug("==> %d --- %s  ", no, trie[no].bad ? "BAD" : "");
	for (int i = 1; i <= n; i++) debug("%d", bt & (1<<i) ? 1 : 0);
	debug("\n");
	
	if ((int)__builtin_popcount(bt) == n) {
	    finish = true;
	    cur = f;
	    break;
	}
	
	for (char c = 'a'; c <= 'j'; c++) {
	    int x = no;
	    x = walk(x, c - 'a');
	    if((x != -1) && !trie[x].bad) {
		if (dist[x][bt | trie[x].end] == 0) {
		    Q.push(pii(x, bt | trie[x].end));
		    dist[x][bt | trie[x].end] = dist[no][bt] + 1;
		    dad[x][bt | trie[x].end] = f;
		}
	    }
	}
	Q.pop();	
    }
    if (!finish) {
	cout << "-" << '\n';
    } else {
	debug("\n\n");
	int at;
	while (cur != pii(root, r)) {
	    int bt = cur.second;
	    int no = cur.first;
	    at = trie[no].c;
	    resp = char(at + 'a') + resp;
	    cur = dad[no][bt];
	}
	if (!finish) cout << '-' << '\n';
	else cout << resp << '\n';
    }
    return 0;
}
