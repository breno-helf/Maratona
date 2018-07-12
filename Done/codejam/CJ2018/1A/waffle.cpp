#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAX = 112;
char grid[MAX][MAX];
int chocolate, dinners, food;
int row[MAX], col[MAX];

void dump(int R, int C, vector<int>& hc, vector<int>& vc) {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            debug("%c", grid[i][j]);
        }
        debug("\n");
    }
    
    debug("~~> ");
    for (int cut : hc) {
        debug("%d ", cut);
    }
    debug("\n");

    debug("~~> ");
    for (int cut : vc) {
        debug("%d ", cut);
    }
    debug("\n");
    
}

bool solve(int R, int C, int H, int V) {
    if (food == 0) return true;
    
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    int acc = 0;
    
    vector<int> hc, vc;
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            row[i] += (grid[i][j] == '@') ? 1 : 0;
        }
        acc += row[i];
        if (acc == food * (V + 1)) {
            hc.push_back(i + 1);
            acc = 0;
        }
    }

    if (hc.size() != (H + 1)) {
        debug("---> Horizontal cuts number wrong %d %d\n", (int)hc.size(), H);
        return false;
    }
    hc[H] = R + 1;
    
    acc = 0;
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) {
            col[j] += (grid[i][j] == '@') ? 1 : 0;
        }
        acc += col[j];
        if (acc == food * (H + 1)) {
            vc.push_back(j + 1);
            acc = 0;
        }
    }

    if (vc.size() != (V + 1)) {
        debug("---> Vertical cuts number wrong %d %d\n", (int)vc.size(), V);
        return false;
    }
    vc[V] = C + 1;
    
    int Hlast = 1;
    int plates = 0;

    dump(R, C, hc, vc);
    
    for (int Hcut : hc) {
        int Vlast = 1;
        for (int Vcut : vc) {
            int sum = 0;
            for (int i = Hlast; i < Hcut; i++) {
                for (int j = Vlast; j < Vcut; j++) {
                    sum += (grid[i][j] == '@') ? 1 : 0;
                }
            }
            debug("==> Sum from [%d, %d] to [%d, %d] is %d\n", Hlast, Vlast, Hcut, Vcut, sum);
            if (sum == food) plates++;
            Vlast = Vcut;
        }
        Hlast = Hcut;
    }

    debug("---> Plates %d\n---> Dinners %d\n", plates, dinners);
    return (plates == dinners);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int R, C, H, V;
        chocolate = 0;
        string ans;

        scanf("%d%d%d%d", &R, &C, &H, &V);
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == '@') chocolate++;
            }
        }
	
        dinners = (H + 1) * (V + 1);
        food = chocolate / dinners;
        debug(" R %d\n C %d\n H %d\n V %d\n Chocolate %d\n Dinners %d\n\n", R, C, H, V, chocolate, dinners);
        if (chocolate % dinners != 0) ans = "IMPOSSIBLE";
        else ans = (solve(R, C, H, V) ? "POSSIBLE" : "IMPOSSIBLE");

        printf("Case #%d: %s\n", t, ans.c_str());
    }
    return 0;
}
