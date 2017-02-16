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

const int MAX = 121;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

vector<int> a(MAX, 0);

double Mean (const vector<int>& x, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
	sum += x[i];
    return sum / size;
}

double sDev (const vector<int>& x, int size) {
    double mean = Mean(x, size);
    double sum = 0;
    for (int i = 0; i < size; i++)
	sum += (x[i] - mean)*(x[i] - mean);
    sum /= n;
    sum = sqrt(sum);
    return sum;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];
    cout << fixed << setprecision(1) << sDev(a, n) << '\n';
    return 0;
}

