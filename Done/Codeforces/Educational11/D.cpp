#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 40005;
int v[MAX], p[MAX], pri[MAX], k;
vector<int> vp;    

void sieve () {
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) 
            for (int j = i*i; j < MAX; j += i) 
                p[j] = true;
    }
    k = 0;
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) 
            pri[k++] = i;
    }
}

int fator (int a, int b) {
    bool f = false;
    int ma = max (a, b), ind;
    for (int i = 0; i < k ; i++) {
        if (a % pri[i] == 0 && b % pri[i] == 0) {
            f = true;
        } 
        if (pri[i] > ma)
            break;
    }
    if (f) 
        return pri[k-1];
    else 
        return 0;
}

int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    if (n == 1) {
        printf ("0\n%d\n", v[0]);
        return 0;
    }
    sieve ();
    int num;
    vp.pb (v[0]);
    for (int i = 1; i < n; i++) {
        num = fator (v[i], v[i-1]);
        if (num == 0) {
            vp.pb (v[i]);
        } else {
            vp.pb (num);
            vp.pb (v[i]);
        }
    }
    int cont = vp.size () - n;
    printf ("%d\n", cont);
    for (int i = 0; i < vp.size (); i++) 
       printf ("%d ", vp[i]);
   printf ("\n"); 
}

