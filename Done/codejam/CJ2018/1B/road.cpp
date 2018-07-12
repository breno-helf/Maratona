#include <bits/stdc++.h>
using namespace std;

const int MAX = 112;

int D[MAX], A[MAX], B[MAX];
int S;

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf("%d", &S);
        for (int i = 0; i < S; i++) {
            scanf("%d %d %d", D + i, A + i, B + i);
        }

        map<int, int> mapa;
        int ans = 0;
        
        for (int i = 0; i < S; i++) {
            map<int, int> E, W;
            int N, M;
            bool x = false, y = false;
            for (int j = i; j < S; j++) {
                int e = D[j] + A[j];
                int w = D[j] - B[j];

                if (j == i) {
                    E[e]++;
                    W[w]++;
                    if (j - i + 1 > ans) { ans = j - i + 1; mapa[ans]++; };
                    continue;
                }
                
                if (x && e == N) {
                    if (j - i + 1 > ans) { ans = j - i + 1; mapa[ans]++; };
                    continue;
                }
                if (y && w == M) {
                    if (j - i + 1 > ans) { ans = j - i + 1; mapa[ans]++; };
                    continue;
                }

                if (!x && !y) {
                    if (E[e] > 0 && W[w] > 0) {
                        if (j - i + 1 > ans) { ans = j - i + 1; mapa[ans]++; };
                        continue;
                    }
                    else if (E[e] > 0) {
                        x = true;
                        N = e;
                    } else if (E[e] == 0 && W[w] > 0) {
                        y = true;
                        M = w;
                    } else {
                        break;
                    }
                } else if (!x || !y) {
                    if (!x) {
                        x = true;
                        N = e;
                    } else if (!y) {
                        y = true;
                        M = w;
                    }
                } else {
                    break;
                }

                if (j - i + 1 > ans) { ans = j - i + 1; mapa[ans]++; };
            }
        }
        
        printf("Case #%d: ", t);
        printf("%d %d\n", ans, mapa[ans]);
    }
    
    return 0;
}
