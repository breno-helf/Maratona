//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int main() {
    int n;
    int a, b;
    scanf("%d", &n);

    for (int i = 3; i <= 1000; i++) {
	n = i;
	printf("%d --> ", i);
	if (n % 2 == 0) {
	a = n/2 - 1;
	b = n/2 + 1;
	while(__gcd(a, b) != 1) {
	    a--;
	    b++;
	    assert(a > 0 && b < n);
	}
	printf("%d %d\n", a, b);
    } else {
	a = n/2;
	b = (n + 1)/2;

	while (__gcd(a, b) != 1) {
	    a--;
	    b++;
	    assert(a > 0 && b < n);
	}
	
	printf("%d %d\n", a, b);	
    }
    }
    return 0;
}

