//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct node {
    int p;
    map<char, int> nxt;
    int sl;
    char c;
    bool end;
} trie[5 * MAX];

int cnt;

void add (const string& s) {
    int sz = s.size();
    int t = 0;
    for (int i = 0; i < sz; i++) {
	char c = s[i];
	if (trie[t].nxt[c] == -1) {
	    int son = cnt++;
	    trie[son].c = c;
	    trie[son].p = t;
	    trie[t].nxt[c] = son;
	}
	t = trie[t].nxt[c];

	if (i == (sz - 1))
	    trie[t].end |= true;
    }    
}

void aho () {
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
	int t = Q.front();
	Q.pop();
	int w = trie[t].p;
	if (w != -1) {
	    w = trie[w].sl;
	    while (w != -1 && trie[w].nxt[trie[t].c] == -1) {
		w = trie[w].sl;
	    }
	    trie[t].sl = (w != -1) ? trie[w].nxt[trie[t].c] : 0;
	    trie[t].end |= trie[trie[t].sl].end;
	}
	for (char c = 'a'; c <= 'z'; c++)
	    if(trie[t].nxt[c] != -1) Q.push(trie[t].nxt[c]);
	for (char c = 'A'; c <= 'Z'; c++)
	    if(trie[t].nxt[c] != -1) Q.push(trie[t].nxt[c]);
	for (char c = '0'; c <= '9'; c++)
	    if(trie[t].nxt[c] != -1) Q.push(trie[t].nxt[c]);
	
    }
}

double dp[5 * MAX][MAX];

map<char, double> p;

double solve (int id, int tam) {
    if (tam == 0) return 1.0;
    double &res = dp[id][tam];
    if (res != -1.0) return res;
    res = 0.0;
    for (char c = 'a'; c <= 'z'; c++) {
	int go = id;
	while (go != -1 && trie[go].nxt[c] == -1)
	    go = trie[go].sl;
	go = (go == -1) ? 0 : trie[go].nxt[c];
	if (!trie[go].end) res += p[c] * solve(go, tam - 1);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
	int go = id;
	while (go != -1 && trie[go].nxt[c] == -1)
	    go = trie[go].sl;
	go = (go == -1) ? 0 : trie[go].nxt[c];
	if (!trie[go].end) res += p[c] * solve(go, tam - 1);
    }
    for (char c = '0'; c <= '9'; c++) {
	int go = id;
	while (go != -1 && trie[go].nxt[c] == -1)
	    go = trie[go].sl;
	go = (go == -1) ? 0 : trie[go].nxt[c];
	if (!trie[go].end) res += p[c] * solve(go, tam - 1);
    }   
    return res;
}


int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
	cnt = 1;
	for (int i = 0; i < 5 * MAX; i++) {
	    for (char c = 'a'; c <= 'z'; c++)
		trie[i].nxt[c] = -1;
	    for (char c = 'A'; c <= 'Z'; c++)
		trie[i].nxt[c] = -1;
	    for (char c = '0'; c <= '9'; c++)
		trie[i].nxt[c] = -1;
	    trie[i].p = -1;
	    trie[i].sl = -1;
	    trie[i].end = false;
	    trie[i].c = -1;
	    for (int j = 0; j < MAX; j++)
		dp[i][j] = -1.0;
	}
	
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
	    string s;
	    cin >> s;
	    add(s);
	}

	for (char c = 'a'; c <= 'z'; c++)
	    p[c] = 0.0;
	for (char c = 'A'; c <= 'Z'; c++)
	    p[c] = 0.0;
	for (char c = '0'; c <= '9'; c++)
	    p[c] = 0.0;
	aho();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	    char c;
	    double d;
	    cin >> c >> d;
	    p[c] = d;
	}

	int l;
	cin >> l;
	cout << "Case #" << cas << ": ";
	cout << fixed << setprecision(6) << solve(0, l) << '\n';
    }
    return 0;
}
