//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

double v[6] = {0, 4.00, 4.50, 5.00, 2.00, 1.50};
int n, id;
int main () {
    cin >> id >> n;
    cout << "Total: R$ ";
    cout << fixed << setprecision(2) << n * v[id] << '\n';
}

