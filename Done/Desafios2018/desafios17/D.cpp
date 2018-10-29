#include<bits/stdc++.h>
using namespace std;

typedef bitset<8> byte;

struct Comparer {
    bool operator() (const byte &b1, const byte &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};

map<byte, byte, Comparer> M;

int main() {
    for (int k = 0; k < (1<<8); k++) {
        byte x = (byte)k;
        byte y = x ^ (x << 1);

        M[y] = x;
    }

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        byte y = (byte)k;
        int x = M[y].to_ulong();
        printf("%d ", x);
    }

    printf("\n");
}
