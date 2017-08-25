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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int d;
int x[2], y[2];
vector<int> commands;

bool inc() {
    int nx = x[0] + dx[d];
    int ny = y[0] + dy[d];

    int d0 = abs(x[0] - x[1]) + abs(y[0] - y[1]);
    int d1 = abs(nx - x[1]) + abs(ny - y[1]);

    return (d0 < d1);
}

void improve() {
    while (inc()) {
	d = (d + 1) % 4;
	commands.pb(0);
    }
    
    if (d == 1 || d == 3) {
	commands.pb(abs(x[0] - x[1]));
	x[0] = x[0] + abs(x[0] - x[1]) * dx[d];
    } else {
	commands.pb(abs(y[0] - y[1]));
	y[0] = y[0] + abs(y[0] - y[1]) * dy[d];
    }
}

int main() {
    char c;
    scanf("%d %d %c", &x[0], &y[0], &c);
    scanf("%d %d", &x[1], &y[1]);

    if (x[0] == x[1] && y[0] == y[1]) {
	puts("0");
	return 0;
    }
    
    if (c == 'N') {
	d = 0;
    } else if (c == 'E') {
	d = 1;
    } else if (c == 'S') {
	d = 2;
    } else d = 3;


    while (x[0] != x[1] || y[0] != y[1])
	improve();

    printf("%d\n", (int)commands.size());

    for (int k : commands) {
	if (k == 0) puts("D");
	else printf("A %d\n", k);
    }
}
