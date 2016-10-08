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

const int MAXN=62;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll n, m, t;

struct matrix {
    ll a[MAXN][MAXN];
    matrix() {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = 0;//(int)(i == j);
    }
    matrix operator*(matrix q) {
        matrix ret;
        ret = matrix();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++)
                    ret.a[i][j] += (a[i][k]*(q.a[k][j]))%MOD;

                ret.a[i][j] %= MOD;
            }
        }
        return ret;
    }
};

matrix id() {
    matrix ret;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            ret.a[i][j] = (ll)(i == j);
    return ret;
}


matrix fexp(matrix a, ll e) {
    matrix ret;
    ret = id();
    matrix pow = a;
    
    for(int i = 0; i < 31; i++) {
        if(e&(1<<i)) ret = ret*pow;
        pow = pow*pow;
    }
    return ret;
}

int main() {
    for(scanf("%lld", &t); t; t--) {
        scanf("%lld%lld", &m, &n);
        matrix z;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                scanf("%lld", &z.a[i][j]);
        z = fexp(z, n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                printf("%lld%c", z.a[i][j], (j == (m - 1)) ? '\n' : ' ');
            }
        }
    }
    return 0;
}






