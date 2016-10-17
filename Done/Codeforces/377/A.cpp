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

const int MAXN=31321;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int k, r;


int main() {
    scanf("%d%d", &k, &r);
    int resp = 10;
    for(int i = 1; i <= 10; i++) {
        if((k*i - r)%10 == 0 || (k*i)%10 == 0) {
            resp = i;
            break;
        }
    }
    printf("%d\n", resp);
}



