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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;
const long double pi = acos(-1);

int n;
long double r;
long double a[MAXN];
long double A;
int main () {
    cin >> n >> r;
    for (int i = 0; i < n; i++)
	cin >> a[i];
    long double resp = 0;
    A = pi*r*r;
    resp += A;
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
	long double d = a[i] - a[i - 1];
	long double A = a[i], B = a[i - 1];
	resp += A;
	if(d < 2*r) {
	    long double x = (B*B - A*A)/(2*(A - B));
	    long double y1 = 
    }
    cout << fixed << setprecision(10) << resp << '\n';
    return 0;
}

