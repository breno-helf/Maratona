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

double a, b, c;

int main () {
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta < 0 || !a) cout << "Impossivel calcular\n";
    else {
	cout << fixed << setprecision(5) << "R1 = " << (-b + sqrt(delta)) / (2 * a) << '\n';
	cout << fixed << setprecision(5) << "R2 = " << (-b - sqrt(delta)) / (2 * a) << '\n';	
    }
}

