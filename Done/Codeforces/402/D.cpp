#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string T, p;
int a[MAX];
int tam;

struct node {
    int p;
    int nxt[26];
    int sl;
    char c;
    bool end;
} trie[MAX];

int root = 0;
int cnt = 1;

void add (const string& s) {
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
	    trie[t].end = true;
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
	if (w != -1) {
	    w = trie[w].sl;
	    while (w != -1 && trie[w].nxt[(int)trie[t].c] == -1) {
		w = trie[w].sl;
	    }
	    trie[t].sl = (w != -1) ? trie[w].nxt[(int)trie[t].c] : root;
	    trie[t].end |= trie[trie[t].sl].end;
	}
	for (char c = 'a'; c <= 'z'; c++)
	    if(trie[t].nxt[c - 'a'] != -1) Q.push(trie[t].nxt[c - 'a']);
    }
}



bool test (int id) {
    debug("--> %d\n", id);
    if ((tam - id - 1) < (int)p.size()) {
    }
    string s = "";
    set<int> rem;
    for (int i = 0; i < id; i++)
	rem.insert(a[i]);
    for (int i = 0; i < tam; i++) {
	if (rem.find(i) == rem.end()) s += T[i];
    }
    debug(">>> %s\n", s.c_str());
    int no = 0;
    for (char c : s) {
	if (trie[no].nxt[c - 'a'] != -1) no = trie[no].nxt[c - 'a'];
	if (trie[no].end) return true;
    }
    return false;
}


int main () {
    for (int i = 0; i < MAX; i++) {
	for (int j = 0; j < 26; j++) trie[i].nxt[j] = -1;
	trie[i].p = -1;
	trie[i].sl = -1;
	trie[i].end = false;
	trie[i].c = 0;
    }
    cin >> T >> p;
    add(p);
    aho();
    tam = T.size();
    for (int i = 0; i < tam; i++) {
	cin >> a[i];
	a[i]--;
    }
    int l = 0, r = tam - 1;
    while (l < r) {
	int mid = (l + r + 1) / 2;
	debug("-- %d %s\n", mid, test(mid) ? "good" : "bad");
	if (test(mid)) l = mid;
	else r = mid - 1;
	debug("%d %d\n", l, r);
    }
    cout << l << '\n';
}


