#include <bits/stdc++.h>
using namespace std;

const int MAX = 512345;

int l, r;
string s;
string t;
int z[MAX];


int main ()
{
    cin >> s;
    string k = s;
    reverse(k.begin(), k.end());
    
    t = s + '#' + k;

    l = r = 0;
    
    for (int i = 1; i < (int)t.size(); i++) {
	if (i <= r)
	    z[i] = min(z[i - 1], r - i + 1);

	while (z[i] + i < (int)t.size() && t[z[i] + i] == t[z[i]])
	    z[i]++;

	if (r < i + z[i] - 1) {
	    l = i;
	    r = i + z[i]  - 1;
	}		
    }
    int resp = 1;
    for (int i = 0; i < (int)t.size(); i++)
	resp = max(resp, z[i]);

    cout << resp << '\n';
}
