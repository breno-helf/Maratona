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

int n;
ll resp, t[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%lld", t + i);
    sort(t, t + n);
    resp = 0;
    int j = n;
    
    while (j >= 4) {
	ll a = t[0], b = t[1];
	ll c = t[j - 2], d = t[j - 1];
	resp += min(2 * a + c + d, a + 2 * b + d);
	j -= 2;
    }
    if (j == 1) resp += t[0];
    else if (j == 2) resp += t[1];
    else if (j == 3) resp += t[0] + t[1] + t[2];
    printf("%lld\n", resp);
}

