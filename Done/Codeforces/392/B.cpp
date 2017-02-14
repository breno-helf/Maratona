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

const int MAX = 121;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
int resp[6];
map<char, int> m;
map<int, char> r;
int p[5];
int main () {
    cin >> s;
    m['R'] = 0;
    m['B'] = 1;
    m['Y'] = 2;
    m['G'] = 3;
    r[0] = 'R';
    r[1] = 'B'; 
    r[2] = 'Y';
    r[3] = 'G';	
    m['!'] = 4;
    
    int cnt = 0, tam, idx = 0;
    for (char c : s) {
	if (c == '!')
	    cnt++;
	p[m[c]] = idx++;
    }

    tam = s.size();

    while (cnt > 0) {
	for (int k = 0; k < 4; k++) {
	    for (int i = p[k]; i < tam; i += 4) {
		if(s[i] == '!') {
		    cnt--;
		    s[i] = m[k];
		    resp[k]++;
		}
	    }
	    for (int i = p[k]; i >= 0;  i -= 4) {
		if(s[i] == '!') {
		    cnt--;
		    s[i] = m[k];
		    resp[k]++;
		}
	    }
	}
    }
    
    cout << resp[0] << ' ' << resp[1] << ' ' << resp[2] << ' ' << resp[3] << '\n'; 
}

