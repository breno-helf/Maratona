#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 122;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int a[MAX], b[MAX];
int A[MAX], B[MAX];
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	A[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
	cin >> b[i];
	B[b[i]]++;
    }
    bool ok = true;
    int c = 0, d = 0;
    for (int i = 1; i <= 100; i++) {
	if ((A[i] + B[i]) % 2) {
	    ok = false;
	}
	if (A[i] > B[i]) {
	    c += A[i] - (A[i] + B[i]) / 2;
	} else if (B[i] > A[i]) {
	    d += B[i] - (A[i] + B[i]) / 2;
	}
    }
    if (ok)
	cout << max(c, d) << '\n';
    else
	cout << -1 << '\n';
}

