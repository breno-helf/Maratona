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

int n;
//int crivo[MAXN]
//map<int, int> fat;
//vector<int> prime;

bool primo(int a) {
    for(int i = 2; i*i <= a; i++) {
	if(a%i == 0)
	    return false;
    }
    return true;
}

bool test(int a) {
    ll fat = 1;
    for(int i = 1; i <= a; i++)
	fat *= i;
    ll q = a*a;
    if(fat%q == 0)
	return true;
    else
	return false;
}


int main () {
    scanf("%d", &n);
    // for(int i = 2; i*i <= 1000000000; i++) {
    // 	if(crivo[i] == 0) {
    // 	    prime.pb(i);
    // 	    for(int k = i*i; k*k <= 1000000000; k += i)
    // 		crivo[k] = i;
    // 	}
    // }

    //for(n = 1; n <= 100; n++) {
	//printf("%d  --  ", n);
	if(n == 1)
	    puts("YES");
	
	else if(n == 4)
	    puts("NO");
	
	else if(primo(n)) {
	    puts("NO");
	    
	}
	else
	    puts("YES");
	//   }
}

