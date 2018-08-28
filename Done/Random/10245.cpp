#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;
const double INF = (double)1e4;

struct point {
    double x, y;
    
    point(double X = 0, double Y = 0):
        x(X), y(Y) {}
        
};

int n;
point P[MAX];

double Hdist(point A, point B) {
    return ((A.x - B.x));
}

double dist(point A, point B) {
    double D = ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));

    //printf("(%doubled, %doubled) -- (%doubled, %doubled) --> %doubled\n", A.x, A.y, B.x, B.y, D);
    
    return sqrt(D);
}
bool cmpX(point A, point B) {
    if (A.x != B.x) return (A.x < B.x);
    return (A.y < B.y);
}

bool cmpY(point A, point B) {
    if (A.y != B.y) return (A.y < B.y);
    return (A.x < B.x);
}

double closestPair(int L, int R) {
    if (L >= R) return INF;

    if (R - L < 3) {
        double ans = INF;
        for (int i = L; i < R; i++) {
            for (int j = i + 1; j <= R; j++) {
                ans = min(ans, dist(P[i], P[j])); 
            }
        }
    }

    int M = (L + R) / 2;

    double E = closestPair(L, M);
    double D = closestPair(M + 1, R);
    double ans = min(E, D);
    
    point temp[MAX];
    int tam = 0;
    
    for (int i = L; i <= R; i++) {
        if (Hdist(P[i], P[M]) < ans) temp[tam++] = P[i];
    }

    sort(temp, temp + tam, cmpY);

    for (int i = 0; i < tam; i++) {
        for (int j = 1; j <= 10 && i + j < tam; j++) {
            ans = min(ans, dist(temp[i], temp[i + j]));
        }        
    }

    return ans;
}

int main() {
    while (scanf("%d", &n)) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        sort(P, P + n, cmpX);
        
        double dist = closestPair(0, n - 1);

        if (dist >= INF) {
            printf("INFINITY\n");
        } else {
            printf("%.4lf\n", dist);
        }
    }
    
    return 0;
}
