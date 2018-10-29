#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        
        int best = 0;
        double M = 0;
        for (int i = 1; i <= n; i++) {
            double a, b, c;
            scanf("%lf %lf %lf", &a, &b, &c);
            
            double R = b / (2.0 * a);

            double C = -a * R * R + b * R + c; 
            
            if (C > M) best = i;

            M = max(M, C);
        }

        printf("%d\n", best);
    }

    return 0;
}
