//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 70000 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

unordered_map<string, int> subs;
vector<string> g[MAX];

string num[MAX];

bool cmp(string a, string b) {
    return (a.size() < b.size());
}

vector<string> gen(string& s) {
    vector<string> v;
    unordered_set<string> S;
    int tam = s.size();

    for (int k = 0; k < tam; k++) {
	string r = "";
	for (int i = k; i < tam; i++) {
	    r += s[i];
	    S.insert(r);
	}
    }


    for (string k : S) v.emplace_back(k);
    
    sort(v.begin(), v.end(), cmp);
    return v;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
	cin >> num[i];
	g[i] = gen(num[i]);
	for (string s : g[i]) subs[s]++;
    }

    for (int i = 1; i <= n; i++) {	
	for (string s : g[i]) {
	    if (subs[s] == 1) {
		cout << s << '\n';
		break;
	    }
	}
    }

    return 0;
}
