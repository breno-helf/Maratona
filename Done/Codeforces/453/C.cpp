//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int h;
int a[MAX];
int p1[MAX], p2[MAX];
int h1[MAX], h2[MAX];
    
int main() {
    bool ok = true;
    int one = 0;

    int cur = 1;
    int last1 = 0, last2 = 0;
    
    scanf("%d", &h);
    for (int i = 0; i <= h; i++) {
	scanf("%d", a + i);
	
	if (a[i] > 1 && one == 1) {
	    ok = false;
	}
		
	for (int k = 0; k < a[i]; k++) {
	    p1[cur] = last1;
	    p2[cur] = last1;
	    
	    if (a[i] > 1 && one == 1 && k == 0) {
		p2[cur] = last2;
		debug("--> entrei %d\n", i);
	    }

	    cur++;
	}

	if (a[i] > 1) one = 1;
	else if (a[i] == 1) one = 0;
	
	last1 = cur - 1, last2 = cur - 2;
	debug("--> %d %d\n", last1, last2);
    }

    if (ok) {
	puts("perfect");
    } else {
	puts("ambiguous");
	for (int i = 1; i < cur; i++) {
	    printf("%d ", p1[i]);
	}
	printf("\n");
	for (int i = 1; i < cur; i++) {
	    printf("%d ", p2[i]);
	}
	printf("\n");
    }
}


