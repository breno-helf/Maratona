//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

double n;

int main () {
    cin >> n;
    if (n >= 0 && n <= 25) cout << "Intervalo [0,25]\n";
    else if (n > 25 && n <= 50) cout << "Intervalo (25,50]\n";
    else if (n > 50 && n <= 75) cout << "Intervalo (50,75]\n";
    else if (n > 75 && n <= 100) cout << "Intervalo (75,100]\n";
    else cout << "Fora de intervalo" << '\n';
}

