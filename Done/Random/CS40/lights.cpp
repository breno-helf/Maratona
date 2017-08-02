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

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
string s;
int r[MAX], acc[MAX];
ll c[MAX], resp;

int main() {
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    resp = 0;
    int cur = 0;
    
    for (int i = 1; i <= n; i++) {
        int add = (s[i] == '1' ? 1 : 0);
        if ((cur + add) % 2 == 1) {
            resp += c[i];
            acc[i] += 1;
            acc[r[i]] -= 1;
        }
        cur += acc[i];
    }
    cout << resp << '\n';
}
