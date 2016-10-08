//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int q, type;
ll v, u, w;

map<pll, ll> cost;

void increase(ll a, ll b, ll c) {
    int la, lb;
    la = 63 - __builtin_clzll(a);
    lb = 63 - __builtin_clzll(b);
    debug("la e lb -- %d %d\n", la, lb);
    if(la > lb) {
        swap(la, lb);
        swap(a, b);
    }
    while(la != lb) {
        debug("--> increse %lld entre %lld %lld\n", w, b, b/2);
        lb--;
        cost[mp(b, b/2)] += w;
        b /= 2;
    }
    while(a != b) {
        debug("--> increse %lld entre %lld %lld\n", w, b, b/2);
        debug("--> increse %lld entre %lld %lld\n", w, a, a/2);
        cost[mp(a, a/2)] += w;
        cost[mp(b, b/2)] += w;
        a /= 2;
        b /= 2;
    }
}

ll go(ll a, ll b) {
    ll ret = 0;
    int la, lb;
    la = 63 - __builtin_clzll(a);
    lb = 63 - __builtin_clzll(b);
    if(la > lb) {
        swap(la, lb);
        swap(a, b);
    }
    while(la != lb) {
        lb--;
        ret += cost[mp(b, b/2)];
        b /= 2;
    }
    while(a != b) {
        ret += cost[mp(b, b/2)] + cost[mp(a, a/2)];
        a /= 2;
        b /= 2;
    }
    return ret;
}
int main() {
    for(scanf("%d", &q); q; q--) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%lld%lld%lld", &v, &u, &w); 
            increase(v, u, w);
        }
        else {
            scanf("%lld%lld", &v, &u);
            printf("%lld\n", go(v, u));
        }
    }
}
