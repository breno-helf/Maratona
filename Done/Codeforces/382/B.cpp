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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, n1, n2, a[MAXN];

double m1, m2;


int main() {
	cin >> n >> n1 >> n2;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	m1 = m2 = 0;
	sort(a, a + n);
	if(n1 > n2) swap(n1, n2);
	for(int i = 0; i < n1; i++) {
		m1 += a[n - 1 - i];
	}
	for(int i = n1; i < (n1 + n2); i++)
		m2 += a[n - 1 - i];
	m1 /= n1;
	m2 /= n2;
	//	cout << m1 + m2 << '\n';
	printf("%lf\n", m1 + m2);
}

