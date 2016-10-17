//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=512;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int n, k;
vector<int> a;

int solve(int j, vector<int> v) {
    int ret = 0;
    for(int i = j; i <= n; i++) {
        if((v[i] + v[i - 1]) < k) {
            ret += (k - (v[i] + v[i - 1]));
            v[i] += k - (v[i] + v[i - 1]);
        }
    }
    return ret;
}

int psolve(int j, vector<int> &v) {
    int ret = 0;
    for(int i = j; i <= n; i++) {
        if((v[i] + v[i - 1]) < k) {
            ret += k - (v[i] + v[i - 1]);
            v[i] += k - (v[i] + v[i - 1]);
        }
    }
    return ret;
}


int main() {
    scanf("%d%d", &n, &k);
    a.pb(k);
    for(int i = 1; i <= n; i++) {
        int b;
        scanf("%d", &b);
        a.pb(b);
    }
    a.pb(k);
    int resp = INF;
    resp = psolve(1, a);
    printf("%d\n", resp);
    for(int i = 1; i <= n; i++) {
        printf("%d%c", a[i], (i == n) ? '\n' : ' ');
    }
}
