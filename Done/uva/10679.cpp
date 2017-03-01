//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct node {
    node *p;
    map<char, node*> nxt;
    node *sl;
    char c;
    bitset<MAX> end;
    int id;
};

typedef node* trie;
trie root;
int cnt;

void add (const string& s, int num) {
    int sz = s.size();
    trie t = root;
    root->id = 0;
    for (int i = 0; i < sz; i++) {
	char c = s[i];
	if (!t->nxt[c]) {
	    trie son = new node();
	    son->c = c;
	    son->p = t;
	    t->nxt[c] = son;
	}
	t = t->nxt[c];
	if (!t->id)
	    t->id = cnt++;
	if (i == (sz - 1)) t->end.set(num);
    }    
}

void aho () {
    queue<trie> Q;
    Q.push(root);
    while (!Q.empty()) {
	trie t = Q.front();
	Q.pop();
	trie w = t->p;
	if (w) {
	    w = w->sl;
	    while (w && !w->nxt[t->c]) {
		w = w->sl;
	    }
	    t->sl = w ? w->nxt[t->c] : root;
	    t->end |= t->sl->end;
	}
	for (char c = 'a'; c <= 'z'; c++)
	    if(t->nxt[c]) Q.push(t->nxt[c]);
	for (char c = 'A'; c <= 'Z'; c++)
	    if(t->nxt[c]) Q.push(t->nxt[c]);
    }    
}

int main () {
    int n, y;
    cin >> y;
    for (int tt = 0; tt < y; tt++) {
	root = new node();
	cnt = 1;
	string T;
	string p[MAX];
	cin >> T;
	cin >> n;
	for (int i = 1; i <= n; i++) {
	    cin >> p[i];
	    add(p[i], i);
	}
	root->c = '[';
	aho ();
	trie x = root;
	bitset<MAX> resp;
	int tam = T.size();
	for (int i = 0; i < tam; i++) {
	    while (x && !x->nxt[T[i]]) {
		x = x->sl;
	    }
	    x = x ? x->nxt[T[i]] : root;
	    resp |= x->end;
	}

	for (int i = 1; i <= n; i++) {
	    if (resp[i])
		puts("y");
	    else
		puts("n");
	}

	queue<trie> Q;
	Q.push(root);

	while (!Q.empty()) {
	    trie t = Q.front();
	    for (char c = 'a'; c <= 'z'; c++)
		if (t->nxt[c])
		    Q.push(t->nxt[c]);
	    for (char c = 'A'; c <= 'Z'; c++)
		if (t->nxt[c])
		    Q.push(t->nxt[c]);
	    Q.pop();
	    delete t;
	}	
    }
    return 0;
}

