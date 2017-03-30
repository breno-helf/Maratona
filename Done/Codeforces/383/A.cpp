#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

int main () {
    cin >> n;
    if (n == 0) puts("1");
    else {
	if (n % 4 == 0) puts("6");
	else if (n % 4 == 1) puts("8");
	else if (n % 4 == 2) puts("4");
	else puts("2");	
    }
    return 0;
}

