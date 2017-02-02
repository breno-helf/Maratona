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

const int MAX = 112312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const long double eps = 1e-9;

double s, p;
double d;
int n;

int main () {
    cin >> s >> p;
    n = INF;
    
    for (int i = 1; i < 30; i += 1) {
	d = 1.0;

	if (s > p && i == 1)
	    continue;
	
	for(int k = 0; k < i; k++)
	    d *= (s/(double)i);
	
	if(d >= p) {
	    n = i;
	    break;
	}
    }

    if(n != INF)
	cout << n << endl;
    else
	cout << -1 << endl;

}

