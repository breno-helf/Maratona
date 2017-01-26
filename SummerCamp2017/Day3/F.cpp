#include <bits/stdc++.h>
using namespace std;

int best = -1;
vector<int> ans;
vector<int> v;

int get(vector<int>& g, int& ini, int& fim) {
    int ret = 0;
    for (int p : v) 
        if (p >= g[ini]) ret++;
    for (int p : g) {
        if (p < g[ini]) ret++;
    }
    return ret * (fim - ini);
}

int test(vector<int>& g) {
    int cur = 0;
    for (int i = 0; i < 4;) {
        for (int k = i+1; k <= 4; k++) {
            if (k == 4 || g[k] - g[i] != k - i) {
                cur += get(g, i, k);
                i = k;
                break;
            }
        }
    }
    if (cur > best) {
        ans = g;
        best = cur;
    }
    return cur;
}

int main()
{
    for (int i = 0,a; i < 4; i++) {
        scanf("%d", &a);
        v.push_back(a-1);
    }

    for (int a = 0; a < 51 - 3; a++) {
        for (int b = a+1; b < 51 - 2; b++) {
            for (int c = b+1; c < 51 - 1; c++) {
                for (int d = c+1; d < 51; d++) {
                    vector<int> toTest{a,b,c,d};
                    test(toTest);
                }
            }
        }
    }

    for (int p : ans) {
        printf("%d ", p+1);
    }
    printf("\n");
}
