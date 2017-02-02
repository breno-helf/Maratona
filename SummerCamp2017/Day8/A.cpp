//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int a[MAX], resp[MAX];

int main () {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    memset(resp, 0, sizeof(resp));
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        debug("%d ",);
        if(a[i] >= 1) {
	    resp[i + a[i] - 1] = max(a[i], resp[i + a[i] - 1]);
        }
    }
    int best = 0;

    for (int i = n - 1; i >= 0; i--) {
	resp[i] = max(best, resp[i]);
	best = max(best, resp[i]);
	best--;
    }
    debug("\n");
    for(int i = 0; i < n; i++)
        cout << resp[i] << ' ';
    cout << '\n';
    return 0;
}

