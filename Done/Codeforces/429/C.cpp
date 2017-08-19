//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int m, a[MAX], b[MAX];
pii A[MAX], B[MAX];
int id[MAX];
int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
	scanf("%d", a + i);
	A[i] = pii(a[i], i);
    }
    for (int i = 0; i < m; i++) {
	scanf("%d", b + i);
	B[i] = pii(b[i], i);
    }
    sort(a, a + m);
    reverse(a, a + m);
    sort(B, B + m);
    for (int i = 0; i < m; i++) {
	id[B[i].second] = a[i];
    }

    for (int i = 0; i < m; i++)
	printf("%d%c", id[i], (i + 1) == m ? '\n' : ' ');
    return 0;
}

