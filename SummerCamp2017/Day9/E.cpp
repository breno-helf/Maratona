#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 10;

int G[MAXN][MAXN], n;
int r[MAXN], k;

vector <int> resp;

int dp[MAXN][MAXN];

int f (int v, int pos)
{
	//cout << "----";
	//cout << v << ' ' << pos << '\n';

	if (dp[v][pos] == -1)
	{
		if (pos > k)
			return (dp[v][pos] = 1);

		dp[v][pos] = 0;

		for (int i = 1; i <= n; i++)
			if (G[v][i] == r[pos])
				dp[v][pos] |= f (i, pos + 1);
	}

	return dp[v][pos];
}

void solve ()
{
	memset (dp, -1, sizeof (dp));

	f (1, 1);

	for (int i = 1; i <= n; i++)
		if(dp[i][k + 1] == 1)		
			resp.push_back (i);
}

int main () {

    cin.sync_with_stdio (false);
    
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    cin >> n;
    for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
	    	cin >> G[i][j];

    cin >> k;

    for (int i = 1; i <= k; i++)
		cin >> r[i];
    
    solve();

    cout << resp.size() << '\n';

    sort (resp.begin(), resp.end());

    for (int i = 0; i < resp.size(); i++)
    	cout << resp[i] << " ";

    cout << '\n';

    return 0;
}
