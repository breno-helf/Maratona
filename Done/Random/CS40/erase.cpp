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

int n, a[MAX], v[MAX];
int sum;
int main() {
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        v[a[i]]++;
    }
    int m = INF;
    for (int i = 1; i <= 1000; i++) {
        m = min(m, sum - v[i] * i);
    }
    cout << m << '\n';
}
