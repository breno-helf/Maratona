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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, l;
int a[MAXN];

int main() {
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
	int b;
	cin >> b;
	a[b]++;
    }
    int resp = 1;
    for(int i = 0; i <= 100000; i++) {
	if(a[i]%l != 0)
	    resp = 0;
    }
    if(resp)
	cout << "OK" << '\n';
    else
	cout << "ARGH!!1" << '\n';
    return 0;
}
