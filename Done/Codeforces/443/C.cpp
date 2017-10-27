//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const int LIM = (1<<10);

int n, x[MAX], t[MAX];
int num[5];

bool test() {
    for (int k = 0; k < LIM; k++) {
	int st = k;
	int ot = k;

	for (int i = 0; i < n; i++) {
	    if (t[i] == 1) st &= x[i];
	    else if (t[i] == 2) st |= x[i];
	    else st ^= x[i];
	}

	for (int i = 1; i <= 4; i++) {
	    if (i == 1 || i == 4) ot &= num[i];
	    else if (i == 2) ot |= num[i];
	    else ot ^= num[i];
	}

	if (ot != st) {
	    debug("(%d) %d %d\n", k, ot, st);
	    return false;
	}
    }

    return true;
}

int main() {
    scanf("%d", &n);

    int one = (1<<10) - 1;
    int zero = 0;
    
    for (int i = 0; i < n; i++) {
	char c;
	scanf(" %c %d", &c, x + i);
	if (c == '&') {
	    t[i] = 1;
	    one &= x[i];
	    zero &= x[i];
	}
	else if (c == '|') {
	    t[i] = 2;
	    one |= x[i];
	    zero |= x[i];
	}
	else {
	    t[i] = 3;
	    one ^= x[i];
	    zero ^= x[i];
	}
    }
    
    for (int k = 0; k < 10; k++) {
	int b = (1<<k);
	if (!(b&zero) && !(b&one)) continue;
	    
	if (b&zero && b&one) {
	    num[1] += (1<<k);
	    num[2] += (1<<k);
	    num[4] += (1<<k);		 
	}

	if (b&zero && !(b&one)) {
	    num[1] += (1<<k);
	    num[3] += (1<<k);
	    num[4] += (1<<k);
	}

	if (!(b&zero) && b&one) {
	    num[1] += (1<<k);
	    num[4] += (1<<k);
	}	
    }

    printf("4\n");

    for (int i = 1; i <= 4; i++) {
	if (i == 1 || i == 4) printf("& ");
	else if (i == 2) printf("| ");
	else printf("^ ");

	printf("%d\n", num[i]);	
    }
    
    
    //test();
}

