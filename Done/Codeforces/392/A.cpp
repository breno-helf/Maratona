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

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX];

int main () {
    ll resp = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];
    sort(a, a + n);
    int mx = a[n - 1];
    for (int i = 0; i < n; i++)
	resp += mx - a[i];
    cout << resp << endl;
}

