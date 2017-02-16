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

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
vector<int> a(MAX, 0);

int median (vector<int> x, int size) {
    int ret;
    if (size % 2) {
	ret = x[size / 2];
    } else {
	ret = (x[size / 2] + x[(size - 1) / 2]) / 2;
    }
    return ret;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    sort(a.begin(), a.begin() + n);
    
    if (n % 2) {
	cout << median(a, n/2) << '\n' << median(a, n) << '\n';
	for (int i = 0; i <= n/2; i++)
	    a.erase(a.begin());
	cout << median(a, n/2) << '\n';
    } else {
	cout << median(a, n/2) << '\n' << median(a, n) << '\n';
	for (int i = 0; i <= (n - 1)/2; i++)
	    a.erase(a.begin());
	cout << median(a, n/2) << '\n';
    }
    return 0;
}

