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

const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

vector<int> s;
vector<pii> a(MAX, pii(0, 0));

double median (const vector<int>& x, int size, int start) {
    double ret;
    if (size % 2) {
	ret = x[start + size / 2];
    } else {
	ret = ((double)x[start + size / 2] +
	       (double)x[start + (size - 1) / 2]) / 2.0;
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i].first;
    for (int i = 0; i < n; i++)
	cin >> a[i].second;
    
    sort(a.begin(), a.begin() + n);
    for (int i = 0; i < n; i++) {
	for (int k = 0; k < a[i].second; k++)
	    s.pb(a[i].first);
    }
    n = s.size();
    if (n % 2) {
	double print = median(s, n/2, n/2 + 1) - median(s, n/2, 0);
	cout << fixed << setprecision(1) << print << '\n';
    }
    else {
	double print = median(s, n/2, n/2) - median(s, n/2, 0);
	cout << fixed << setprecision(1) << print << '\n';
    }
    return 0;
}

