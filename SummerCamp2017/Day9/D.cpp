#include <bits/stdc++.h>
using namespace std;

int const N = 1e3 + 10;

int n, m;

int dp[N];
int dis[N];

vector <int> dag[N], adj[N];

void bfs (int root)
{
	memset (dis, -1, sizeof (dis));

	queue <int> Q;

	Q.push (root);
	dis[root] = 0;

	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop ();

		for (int i = 0; i < adj[v].size(); i++)
		{
			int u = adj[v][i];

			if (dis[u] == -1)
			{
				dis[u] = dis[v] + 1;
				dag[v].push_back (u);
				
				Q.push (u);
			}
			else
				if (dis[u] == dis[v] + 1)
					dag[v].push_back (u);
		}
	}
}

int f (int v)
{
	if (dp[v] == -1)
	{
		dp[v] = 0;

		for (int i = 0; i < dag[v].size(); i++)
		{
			int u = dag[v][i];

			if (!f (u))
			{
				dp[v] = 1;
				return 1;
			}
		}
	}

	return dp[v];
}

void solve ()
{
	bfs (1);

	memset (dp, -1, sizeof (dp));
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back (v);
		adj[v].push_back (u);
	}

	solve ();

	if (f (1) == 0)
		cout << "Nikolay\n";
	else
		cout << "Vladimir\n";

	return 0;
}	