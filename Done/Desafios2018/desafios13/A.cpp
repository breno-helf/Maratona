#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 10;

int Nx, Ny;
double w;
double A[MAX], B[MAX];

int main() {
    while (true) {
        cin >> Nx >> Ny >> w;
        if (Nx == 0 && Ny == 0 && w == 0) break;

        w /= 2.0;
        
        for (int i = 0; i < Nx; i++)
            cin >> A[i];

        for (int i = 0; i < Ny; i++)
            cin >> B[i];

        sort(A, A + Nx);
        sort(B, B + Ny);

        double mx = 0;

        for (int i = 0; i < Nx; i++) {
            if (A[i] - w <= mx)
                mx = max(mx, A[i] + w);
        }

        if (mx < 75) {
            cout << "NO" << '\n';
            continue;
        }

        mx = 0;

        for (int i = 0; i < Ny; i++) {
            if (B[i] - w <= mx)
                mx = max(mx, B[i] + w);            
        }

        if (mx < 100) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
    }
    
}
