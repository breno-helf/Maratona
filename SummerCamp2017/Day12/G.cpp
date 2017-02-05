#include <bits/stdc++.h>
using namespace std;

int const maxN = 6e2 + 10;
int const maxK = 55;
int const INF = -1e9;

typedef pair <int, int> pii;

int N, K;

long long dp[maxK][maxN];

long long entra[maxN][maxN];

pii lastPointer[maxK][maxN];

long long sumEntra[maxN];
long long sai[maxN];
long long sumSai[maxN];

void compute ()
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dp[j][i] = INF;

	dp[0][0] = 0; // Base Case

	for (int i = 1; i <= N; i++)
	{
		long long inPeople, outPeople;

		// K = 1

		inPeople = sumEntra[i];
		outPeople = sumSai[i];
		
		dp[1][i] = inPeople - outPeople;
		lastPointer[1][i] = pii (0, 0);

		// end K = 1

		for (int k = 2; k <= K; k++)
		{
			int falta = 0;
			outPeople = 0;

			for (int j = i - 1; j >= k - 1; j--)
			{
				inPeople = sumEntra[i] - sumEntra[j];
				
				if (dp[k][i] < dp[k - 1][j] + inPeople - outPeople)
				{
					dp[k][i] = dp[k - 1][j] + inPeople - outPeople;
					lastPointer[k][i] = pii (k - 1, j);
				}

				outPeople += entra[j][++falta];
			}
		}
	}
}

void solve ()
{
	compute ();

	long long ans = -1;
	int pointer = -1;

	for (int i = K; i <= N; i++)
		if (dp[K][i] > ans)
		{
			pointer = i;
			ans = dp[K][i];
		}

	vector <int> answer;
	
	pii P = pii (K, pointer);

	while (true)
	{
		int id = P.second;
		int k = P.first;

		if (!k)
		{
			assert (!id);
			break;
		}

		answer.push_back (id);

		P = lastPointer[k][id];
	}

	reverse (answer.begin(),answer.end());

	// cout << ans << '\n';
	for (auto i: answer)
		printf ("%d ", i);

	printf ("\n");
}

int main ()
{
	scanf ("%d %d", &N, &K);

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			long long x;
			cin >> x;

			entra[i][j] = entra[i][j - 1] + x;
			sai[i + j] += x;
		}

		sumEntra[i] = sumEntra[i - 1] + entra[i][N - i];
	}

	for (int i = 1; i <= N; i++)
		sumSai[i] = sumSai[i - 1] + sai[i];

	solve ();
	
	return 0;
}