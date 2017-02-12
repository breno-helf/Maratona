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

const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

char g[MAX][MAX];

queue<pii> pos;

bool check (int i, int j) {
    return (i >= 0 && i < 4 && j >= 0 && j < 4);
}

bool horizontal (int i, int j) {
    if (check(i, j - 1) && check(i, j + 1))
	if (g[i][j - 1] == 'x' && g[i][j + 1] == 'x') return true;
    if (check(i, j - 2))
	if (g[i][j - 1] == 'x' && g[i][j - 2] == 'x') return true;
    if (check(i, j + 2))
	if (g[i][j + 1] == 'x' && g[i][j + 2] == 'x') return true;
    return false;
}

bool vertical (int i, int j) {
    if (check(i - 1, j) && check(i + 1, j))
	if (g[i - 1][j] == 'x' && g[i + 1][j] == 'x') return true;
    if (check(i - 2, j))
	if (g[i - 1][j] == 'x' && g[i - 2][j] == 'x') return true;
    if (check(i + 2, j))
	if (g[i + 1][j] == 'x' && g[i + 2][j] == 'x') return true;    
    return false;
}

bool diagonal (int i, int j) {
    if (check(i + 1, j + 1) && check(i - 1, j - 1))
	if (g[i + 1][j + 1] == 'x' && g[i - 1][j - 1] == 'x') return true;
    if(check(i + 1, j + 1) && check(i + 2, j + 2))
	if (g[i + 2][j + 2] == 'x' && g[i + 1][j + 1] == 'x') return true;
    if(check(i - 1, j - 1) && check(i - 2, j - 2))
	if (g[i - 2][j - 2] == 'x' && g[i - 1][j - 1] == 'x') return true;

    // Other diagonal

    if (check(i - 1, j + 1) && check(i + 1, j - 1))
	if (g[i - 1][j + 1] == 'x' && g[i + 1][j - 1] == 'x') return true;
    if (check(i - 2, j + 2) && check(i - 1, j + 1))
	if (g[i - 2][j + 2] == 'x' && g[i - 1][j + 1] == 'x') return true;
    if (check(i + 2, j - 2) && check(i + 1, j - 1))
	if (g[i + 2][j - 2] == 'x' && g[i + 1][j - 1] == 'x') return true;

    return false;
}

int main () {
    for (int i = 0; i < 4; i++)
	scanf(" %s", g[i]);

    for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++) {
	    if(g[i][j] == '.')
		pos.push(pii(i, j));
	}

    while (!pos.empty()) {
	int i, j;
	i = pos.front().first;
	j = pos.front().second;

	pos.pop();

	if (horizontal(i, j) || vertical(i, j) || diagonal(i, j)) {
	    puts("YES");
	    return 0;
	}	
    }

    puts("NO");
    return 0;
}

