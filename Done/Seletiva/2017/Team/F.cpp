//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 3;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

double R;
double x, y;
int score = 0;
int main() {
    scanf("%lf", &R);

    for (int i = 0; i < 3; i++) {
	scanf("%lf%lf", &x, &y);
	double d = sqrt(x * x + y * y);
	int add = 0;
	for (int k = 10; k > 0; k--) {
	    if (d <= R * (double)(k)) add = max(add, 10 - k + 1);
	}
	score += add;
    }

    printf("%d\n", score);
}

