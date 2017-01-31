	#include <bits/stdc++.h>
	using namespace std;

	int n, m;

	map <string, int> M;
	map <vector <int>, int> mapSet;

	int main ()
	{
			cin.sync_with_stdio (false);
			cin.tie (0);
			cout.tie (0);

			ifstream cin ("input.txt");
			ofstream cout ("output.txt");

			cin >> n;

			int contString = 0;
			int contSet = 0;

			for (int i = 0; i < n; i++)
			{
				int total;
				cin >> total;

				vector <int> vec;
				for (int j = 0; j < total; j++)
				{
					string s;
					cin >> s;

					if (!M[s])
						M[s] = ++contString;

					vec.push_back (M[s]);
				}

				sort (vec.begin(), vec.end());

				for (int mask = 1; mask < (1 << total); mask++)
				{
					vector <int> V;

					for (int k = 0; k < total; k++)
						if ((1 << k) & mask)
							V.push_back (vec[k]);

					mapSet[V]++;
				}
			}

			cin >> m;

			for (int i = 0; i < m; i++)
			{
				int total;
				cin >> total;

				bool ok = true;
				vector <int> V;

				for (int j = 0; j < total; j++)
				{
					string s;
					cin >> s;

					if (!M[s])
						ok = false;

					V.push_back (M[s]);
				}

				sort (V.begin(), V.end());

				if (!ok)
					cout << 0 << '\n';
				else
					cout << mapSet[V] << '\n';
			}

			return 0;
	}