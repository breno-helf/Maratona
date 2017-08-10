#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int ccw[] = {0, 1, 2, 3};
int cw[] = {0, 3, 2, 1};

int main() {
    char c1, c2;
    scanf(" %c %c", &c1, &c2);

    int n;
    scanf(" %d", &n);

    int st, ed;
    if (c1 == '^') st = 0;
    else if (c1 == '>') st = 1;
    else if (c1 == 'v') st = 2;
    else st = 3;

    if (c2 == '^') ed = 0;
    else if (c2 == '>') ed = 1;
    else if (c2 == 'v') ed = 2;
    else ed = 3;

    //printf("%d %d\n", st, ed);
    
    int a, b;
    
    int x, y;

    x = st;

    if (st == 0) y = 0;
    else if (st == 1) y = 3;
    else if (st == 2) y = 2;
    else y = 1;
    
    
    a = cw[(y + n) % 4];
    b = ccw[(x + n) % 4];

    if (a == ed && b == ed) printf("undefined\n");
    else if (a == ed) printf("ccw\n");
    else if (b == ed) printf("cw\n");
    else printf("undefined\n");
}


