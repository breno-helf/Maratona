//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;
 
#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int MAX = 4 * (1e4 + 5);
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
 
string V[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
	      "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
	      
struct node {
    int p;
    int nxt[2];
    int sl;
    char c;
    int end;
} trie[100 * MAX];
 
int cnt;
 
void add (const string& s) {
    int sz = s.size();
    int t = 0;
    for (int i = 0; i < sz; i++) {
	char c = s[i];
	int v = (c == '.') ? 1 : 0;
	if (trie[t].nxt[v] == -1) {
	    int son = cnt++;
	    trie[son].c = v;
	    trie[son].p = t;
	    trie[t].nxt[v] = son;
	}
	t = trie[t].nxt[v];
 
	if (i == (sz - 1))
	    trie[t].end++;
    }    
}
 
int dp[MAX];
map<int, string> code;
string morse;
int resp = 0, tam;
 
int solve (int i) {
  //  debug("%d\n", i);
  if (i == tam) return 1;
  if (dp[i] != -1) return dp[i];
  int &res = dp[i];
  res = 0;
  int no = 0;
  for (int k = 0; k < 80 && (i + k < tam); k++) {
    int c = (morse[i + k] == '.') ? 1 : 0;
    if (trie[no].nxt[c] != -1)
      no = trie[no].nxt[c];
    else break;
    if (trie[no].end) res += trie[no].end * solve(i + k + 1);
  }
  return res;
}
 
int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 26; i++)
	code[i] = V[i];
    int d;
    for (cin >> d; d; d--) {
	resp = 0;
	cnt = 1;
	for (int i = 0; i < 100 * MAX; i++) {
	    for (int j = 0; j < 2; j++)
		trie[i].nxt[j] = -1;
	    trie[i].p = -1;
	    trie[i].c = 0;
	    trie[i].end = 0;
	}
	for (int i = 0; i < MAX; i++)
	  dp[i] = -1;
	
	cin >> morse;
	tam = morse.size();
	dp[tam] = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  string s, r = "";
	  cin >> s;
	  for (auto c : s) r += code[c - 'A']; 
	  add(r);
	}
	
	cout << solve(0) << '\n';
    }
    return 0;
}
