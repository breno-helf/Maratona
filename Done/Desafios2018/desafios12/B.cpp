#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll P = 43;
const int MAX = 5e3 + 10;

int n, k;
char S[MAX / 2][MAX];
set<int> V[MAX];
int POT[MAX];

inline int hashString(char * s) {
    ll hash = 0;
    ll K = 1;
    for (int i = 0; i < n; i++) {
        hash = (hash + K * (ll)(s[i])) % MOD;
        K = (K * P) % MOD;
    }

    return ((int)hash % MOD);
}

inline bool testSwap(int i, int hashValue) {
    return (V[i].count(hashValue) > 0);
}

inline bool testPattern(int hashValue) {
    bool ok = true;

    //printf("Testing %s %d\n", p.c_str(), hashValue);
    
    for (int i = 0; i < k; i++) {
        if (!testSwap(i, hashValue)) {
            ok = false;
            break;
        }
    }
    return ok;
}

int main() {
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf(" %s", S[i]);
    }

    POT[0] = 1;
    for (int i = 1; i <= n; i++)
        POT[i] = ((ll)POT[i - 1] * P) % MOD;

    
    for (int a = 0; a < k; a++) {
        char * p = S[a];
        int hashValue = hashString(p);
        
        V[a].insert(hashValue);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {


                //swap(p[i], p[j]);
                ll I = (POT[i] * ((ll)p[j]) - POT[i] * ((ll)p[i]) + MOD);
                ll J = (POT[j] * ((ll)p[i]) - POT[j] * ((ll)p[j]) + MOD);
                ll diff = (I + J + MOD) % MOD;
                
                hashValue = ((ll)hashValue + diff + MOD) % MOD;

                //hashValue = hashString(p);
                V[a].insert(hashValue);
                
                //printf("(%d, %s) - ", hashValue, p.c_str());
                
                hashValue = ((ll)hashValue - diff + MOD) % MOD;

                //swap(p[i], p[j]);
            }
        }
        //printf("\n");
    }
    
    char * p = S[0];
    
    int hashValue = hashString(p);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll I = (POT[i] * ((ll)p[j]) - POT[i] * ((ll)p[i]) + MOD);
            ll J = (POT[j] * ((ll)p[i]) - POT[j] * ((ll)p[j]) + MOD);
            ll diff = (I + J + MOD) % MOD;
            
            hashValue = ((ll)hashValue + diff + MOD) % MOD;

            if (testPattern(hashValue)) {
                swap(p[i], p[j]);
                printf("%s\n", p);
                return 0;
            }

            hashValue = ((ll)hashValue - diff + MOD) % MOD;    
        }
    }
    
    printf("-1\n");
}
