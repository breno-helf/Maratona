#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 40;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int qtd[MAX];
int cur[MAX];
string s;
int n, k;

int main() {
    cin >> n >> k >> s;

    for (int i = 0; i < n; i++) {
	qtd[s[i] - 'A']++;
    }

    bool ok = true;
    
    for (int i = 0; i < n; i++) {
	if (cur[s[i] - 'A'] == 0) {
	    k--;
	}
	cur[s[i] - 'A']++;
	if (k < 0) ok = false;
	if (cur[s[i] - 'A'] == qtd[s[i] - 'A']) k++;
    }

    if (ok) cout << "NO\n";
    else cout << "YES\n";
}

