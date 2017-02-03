//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int p[MAX], z[MAX], v[MAX];

void z_function () {
    int l, r;
    l = r = 0;
    for (int i = 1; i < n; i++) {
	if (i <= r)
	    z[i] = min(z[i - l], r - i + 1);
	
	while((z[i] + i) < n && v[z[i] + i] == v[z[i]])
	    z[i]++;
	
	if (r < (i + z[i] - 1)) {
	    l = i;
	    r = i + z[i] - 1;
	}
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> p[i];

    int cur = 1;
    v[0] = cur;
    for (int i = 1; i < n; i++) {
	if (p[i] > 0)
	    v[i] = v[p[i] - 1]; 
	else
	    v[i] = ++cur;
    }

    z_function();

    for (int i = 0; i < n; i++)
	cout << z[i] << ' ';
    cout << '\n';
}
