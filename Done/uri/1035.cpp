//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int A, B, C, D;

int main () {
    cin >> A >> B >> C >> D;
    if (B > C && D > A && (C + D) > (A + B) && C > 0 && D > 0 && !(A%2))
	cout << "Valores aceitos\n";
    else
	cout << "Valores nao aceitos\n";
}

