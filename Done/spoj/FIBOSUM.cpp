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

const int MAXN=12321;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

struct matrix {
    ll a[2][2];
    matrix() {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                a[i][j] = 0;//(int)(i == j);
    }
    matrix operator*(matrix q) {
        matrix ret;
        ret = matrix();
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++)
                    ret.a[i][j] += (a[i][k]*(q.a[k][j]))%MOD;

                ret.a[i][j] %= MOD;
            }
        }
        return ret;
    }
};


matrix id() {
    matrix ret;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
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
    int t;
    for(scanf("%d", &t); t; t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        matrix fibN, fibM;
        ll resp;
        fibN = fibM = matrix();
        fibN.a[0][1] = fibN.a[1][1] = fibN.a[1][0] = fibM.a[0][1] = fibM.a[1][1] = fibM.a[1][0] = 1;
        resp = fexp(fibM, m + 2).a[0][1] - fexp(fibN, n + 1).a[0][1];
        if(resp < 0) resp += MOD;
        resp %= MOD;
        assert(resp > 0);
        printf("%lld\n", resp);
    }
    return 0;
}
