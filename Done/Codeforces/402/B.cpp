#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12; 
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
string s;

int main () {
    cin >> s >> k;
    int z = 0;
    for (char c : s) {
	if (c == '0') z++;
    }
    int tam = s.size();
    if (z < k) {
	cout << tam - 1 << '\n';
	return 0;
    } else {
	int r = 0;
	z = 0;
	int i;
	for (i = tam - 1; i >= 0 && z != k; i--) {
	    if (s[i] == '0') z++;
	    else r++;
	}
	if (i < 0) cout << tam - 1 << '\n';
	else cout << r << '\n';	
    }
    return 0;
}


