//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int a[MAX], n;
int acc[MAX], z;
int main () {
    z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	if (i > 0) acc[i] = acc[i - 1] + a[i];
	else acc[i] = a[i];
	if (a[i] == 0) z++;
    }
    
    if (z == n) {
	puts ("NO");
	return 0;
    }

    puts ("YES");

    if (acc[n - 1] != 0) {
	printf("1\n1 %d\n", n);	
    }

    else {
	int end = n - 1;
	while (a[end] == 0) end--;
	
	printf("2\n1 %d\n%d %d\n", end, end + 1, n);
    }
    return 0;
}
