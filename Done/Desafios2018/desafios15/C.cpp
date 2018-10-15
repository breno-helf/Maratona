// Yan, se voce tiver lendo isso
// namoral, se ferrar
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> A, B;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        A.push_back(e);
        B.push_back(e);
    }

    sort(A.begin(), A.end());

    if (A == B) cout << "yes\n";
    else cout << "no\n";
}
