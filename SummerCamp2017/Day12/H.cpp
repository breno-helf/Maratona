#include <bits/stdc++.h>
using namespace std;

int const N = 1e3 + 10;

int T, n, a[N], d[N];

int main ()
{
    scanf ("%d", &T);

    while (T--)
	{
	    scanf ("%d", &n);
	    
	    int winner = 0;
	    
	    for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);

	    d[1] = a[1];
	    
	    for (int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	    }

	    // for (int i = 1; i <= n; i++)
	    // 	cout << d[i] << ' ';
	    // cout << '\n';
	    
	    for (int i = n; i >= 1; i -= 2)
		winner ^= d[i];

	    if (winner == 0)
		cout << "NIE\n";
	    else
		cout << "TAK\n";
	    
	}
	
    return 0;
}
