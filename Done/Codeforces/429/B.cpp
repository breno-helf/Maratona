//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int a[MAX];
int n;
int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
	scanf("%d", a + i);
	cnt += (a[i] % 2);
    }
    if (cnt % 2 == 1) printf("First\n");
    else {
	if (cnt == 0)	
	    printf("Second\n");
	else
	    printf("First\n");
    }
}

