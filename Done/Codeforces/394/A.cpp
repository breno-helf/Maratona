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

const int MAX = 132;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int a, b;

int main () {
    cin >> a >> b;
    if (abs(b - a) <= 1 && !(a == 0 && b == 0))
	cout << "YES\n";
    else
	cout << "NO\n";
}

