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

const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int r1, c1, r2, c2;

int main() {
    cin >> r1 >> c1 >> r2 >> c2;    
    
    if ((r1 + c1) % 2 != (r2 + c2) % 2) cout << -1 << '\n';
    else {
        if (r1 == r2 && c1 == c2) cout << 0 << '\n';
        else if ((r1 - c1) == (r2 - c2) || (r1 + c1) == (r2 + c2)) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    

}
