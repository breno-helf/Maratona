#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 121;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int s, v1, v2, t1, t2;
int a, b;

int main() {
    cin >> s >> v1 >> v2 >> t1 >> t2;
    a = 2 * t1 + v1 * s;
    b = 2 * t2 + v2 * s;

    if (a > b) puts("Second");
    else if (a == b) puts("Friendship");
    else puts("First");
    return 0;
}




