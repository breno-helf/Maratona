//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, k, v[MAXN];
string s;

int main() {
	cin >> n >> k;
	cin >> s;
	int g, t;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] == 'G')
			g = i;
		else if(s[i] == 'T')
			t = i;
	}
	queue<int> e;
	e.push(g);
	while(!e.empty()) {
		int a = e.front();
		v[a] = 1;
		e.pop();
		if(a + k < n) {
			if(s[a + k] != '#' && v[a + k] == 0)
				e.push(a + k);
		}
		if(a - k >= 0) {
			if(s[a - k] != '#' && v[a - k] == 0)
				e.push(a - k);
		}
	}
	if(v[t]) puts("YES");
	else puts("NO");
}


