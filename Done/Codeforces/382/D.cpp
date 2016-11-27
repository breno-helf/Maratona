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

const int MAXN=2131;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


ll n;
bool p, q;
int main() {
	cin >> n;
	q = p = 1;
	for(ll i = 2; i*i <= n; i++) {
		if(n%i == 0)
			p = 0;
		if((n - 2)%i == 0)
			q = 0;
	}
	
	if(p) {
		puts("1");
		return 0;
	}

	if(q) {
		puts("2");
		return 0;
	}
	
	if(n < 4)
		puts("1");
	else if(!(n%2))
		puts("2");
	else {
		if(n == 5)
			puts("1");
		else
			puts("3");
	}
	

}
