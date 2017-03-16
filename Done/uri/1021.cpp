//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 122;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string N = "nota(s) de R$ ";
string M = "moeda(s) de R$ ";
long double a;

int main () {
    cin >> a;
    int x, y;
    x = a;
    cout << "NOTAS:\n";
    cout << (int)(x / 100) << ' ' << N << "100.00\n";
    x %= 100;
    cout << (int)(x / 50) << ' ' << N << "50.00\n";
    x %= 50;
    cout << (int)(x / 20) << ' ' << N << "20.00\n";
    x %= 20;
    cout << (int)(x / 10) << ' ' << N << "10.00\n";
    x %= 10;
    cout << (int)(x / 5) << ' ' << N << "5.00\n";
    x %= 5;
    cout << (int)(x / 2) << ' ' << N << "2.00\n";
    x %= 2;

    cout << "MOEDAS:\n";
    cout << (int)(x / 1) << ' ' << M << "1.00\n";
    y = ((int)(a * 100)) % 100;
    cout << (int)(y / 50) << ' ' << M << "0.50\n";
    y %= 50;
    cout << (int)(y / 25) << ' ' << M << "0.25\n";
    y %= 25;
    cout << (int)(y / 10) << ' ' << M << "0.10\n";
    y %= 10;
    cout << (int)(y / 5) << ' ' << M << "0.05\n";
    y %= 5;
    cout << (int)(y / 1) << ' ' << M << "0.01\n";
    return 0;
}

