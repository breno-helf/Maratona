#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
bool ok = false;
int v[MAX];

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
	int k;
	set<int> s;
	cin >> k;
	for (int j = 0; j < k; j++) {
	    cin >> v[j];
	    s.insert(v[j]);
	}
	bool safe = false;
	bool trai = false;
	for (int j = 0; j < k; j++) {
	    if (s.find(-v[j]) == s.end()) trai = true;
	    else safe = true;
	}
	if (trai && !safe) ok = true;
    }

    printf("%s\n", ok ? "YES" : "NO");
}

