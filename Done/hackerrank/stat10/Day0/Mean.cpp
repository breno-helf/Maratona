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

const int MAX = 2512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
vector<int> a(MAX, 0);

double mean (vector<int> x, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
	sum += x[i];
    return sum / size;
}

double median (vector<int> x, int size) {
    double ret;
    if (size % 2) {
	ret = x[size / 2];
    } else {
	ret = ((double)x[size / 2] + (double)x[(size - 1) / 2]) / 2.0;
    }
    return ret;
}

int mode (vector<int> x, int size) {
    vector<int> count(512345, 0);
    int big = 0, num = -1;
    for (int i = 0; i < size; i++)
	count[x[i]]++;
    for (int i = 0; i <= 100000; i++) {
	if (count[i] > big) {
	    big = count[i];
	    num = i;
	}
    }
    return num;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];

    sort(a.begin(), a.begin() + n);

    for (int i = 0; i < n; i++)
	cout << a[i] << '\n';
    
    cout << fixed << setprecision(1) << mean(a, n) << '\n';
    cout << fixed << setprecision(1) << median(a, n) << '\n';
    cout << mode(a, n) << '\n';
}

