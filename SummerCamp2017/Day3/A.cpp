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

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const double PI = acos(-1);

int n, r, a[MAX];

double A, ans;

int main () {
    cin >> n >> r;
    for (int i = 0; i < n; i++)
	cin >> a[i];

    sort(a, a + n);
    A = PI*r*r;
    ans = A;

    for (int i = 1; i < n; i++) {
	double d = a[i] - a[i - 1];
	double alfa = 2*acos(d/(2*r));
	ans += A;
	if (d/2 < r)
	    ans -= 2*(alfa*r*r/2 - r*r*sin(alfa)/2);
    }
    cout << fixed << setprecision(6) << ans << '\n';
}

