#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
char s[MAX][MAX];

bool test1() {
    bool A = true;
    char color = -1;

    for (int i = 0; i < n/3; i++) {
	for (int j = 0; j < m; j++) {
	    if (color == -1) color = s[i][j];
	    if (color != s[i][j]) A = false;
	}
    }

    if (!A) return false;

    char color2 = -1;
    
    for (int i = n/3; i < (2*n/3); i++) {
	for (int j = 0; j < m; j++) {
	    if (color2 == -1) color2 = s[i][j];
	    if (color2 != s[i][j]) A = false;
	}
    }

    if (!A || color2 == color) return false;

    char color3 = -1;

    for (int i = 2*n/3; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (color3 == -1) color3 = s[i][j];
	    if (color3 != s[i][j]) A = false;
	}
    }

    if (!A || color2 == color3 || color3 == color) return false;

    return true;
}

bool test2() {
    bool A = true;
    char color = -1;

    for (int j = 0; j < m/3; j++) {
	for (int i = 0; i < n; i++) {
	    if (color == -1) color = s[i][j];
	    if (color != s[i][j]) A = false;
	}
    }

    if (!A) return false;

    char color2 = -1;
    
    for (int j = m/3; j < 2*m/3; j++) {
	for (int i = 0; i < n; i++) {
	    if (color2 == -1) color2 = s[i][j];
	    if (color2 != s[i][j]) A = false;
	}
    }

    if (!A || color2 == color) return false;

    char color3 = -1;

    for (int j = 2*m/3; j < m; j++) {
	for (int i = 0; i < n; i++) {
	    if (color3 == -1) color3 = s[i][j];
	    if (color3 != s[i][j]) A = false;
	}
    }

    if (!A || color2 == color3 || color3 == color) return false;

    return true;    
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf(" %s", s[i]);
    }

    bool ok = false;
    
    if (n % 3 == 0) {
	if (test1()) ok = true;
    }

    if (m % 3 == 0) {
	if (test2()) ok = true;
    }

    if (ok) puts("YES");
    else puts("NO");
}

