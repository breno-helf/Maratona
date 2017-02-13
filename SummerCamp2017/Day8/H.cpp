//This code was written by Breno Moura, Codeforces Handle: Brelf
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

const int MAX = 512345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m, k;

int solve (int num, int cur, int kid) {
    if ((cur + m - 1) <= num) {
	if ((cur + m - 1) == kid)
	    return 1;
	else {
	    if (cur + m - 1 < kid)
		return 1 + solve(num - 1, cur + m - 1, kid - 1);
	    else
		return 1 + solve(num - 1, cur + m - 1, kid);
	}		
    } else {
	int nxt = cur + m - 1;
	nxt %= num;
	if (nxt == 0) nxt = num;
	if (nxt == kid)
	    return 1;
	else {
	    if (nxt < kid)
		return 1 + solve(num - 1, nxt, kid - 1);
	    else
		return 1 + solve(num - 1, nxt, kid);
	}
    }
}

int main () {
    cin >> n >> m >> k;
    cout << solve(n, 1, k) << '\n';
}

