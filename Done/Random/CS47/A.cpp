//This code was written by Breno Moura, Codeforces Handle: Brelf

//From University of São Paulo - USP

//If you are trying to hack me I wish you can get it, Good Luck :D

#include <bits/stdc++.h>

using namespace std;



#define debug(args...) fprintf (stderr,args)

#define pb push_back

#define mp make_pair



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



const int MAX = 1123;

const int INF = 0x3f3f3f3f;

const ll  MOD = 1000000007;



int n;

string s;



bool isvowel(int i) {

    return (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' ||

            s[i] == 'o' || s[i] == 'i');

}



int main() {

    cin >> n;

    cin >> s;

    int c = 0;

    for (int i = 1; i < n; i++) {

        if (isvowel(i - 1) && isvowel(i)) c++;   

    }

    cout << c << endl;

}
