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

vector<int> x(MAX), w(MAX);

double weighetedMean (vector<int> a, vector<int> p, int size) {
    double sum = 0;
    int total = 0;
    for (int i = 0; i < size; i++) {
	sum += a[i]*p[i];
	total += p[i];
    }
    return sum / (double)total;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> x[i];
    for (int i = 0; i < n; i++)
	cin >> w[i];
    
    cout << fixed << setprecision(1) << weighetedMean(x, w, n) << '\n';
}

