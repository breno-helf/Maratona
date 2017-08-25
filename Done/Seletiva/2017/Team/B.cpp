//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n;
ll sum;
char s[MAX];

int main() {
    scanf("%lld", &n);
    sum = (n * (n + 1)) / 2;

    if (sum % 2LL == 1LL) {
	puts("-1");
	return 0;
    }

    ll cur = 0;
    memset(s, '-', sizeof(s));
    int i = 1, j = n;
    s[n] = '\0';
    while (cur < sum / 2) {
	cur += j;
	s[j - 1] = '+';
	j--;
	if (cur >= sum / 2) break;
	cur += i;
	s[i - 1] = '+';
	i++;
    }
    
    printf("%s\n", s);
}


