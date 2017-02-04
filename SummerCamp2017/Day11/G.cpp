#include <bits/stdc++.h>
using namespace std;

int T;

int main() 
{
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	cin >> T;

	while (T--)
	{
		string S;
		cin >> S;

		if (S.back() == 'x' || S.back() == 's' || S.back() == 'o')
		{
			S += "es";
			cout << S << '\n';
			continue;
		}

		int sz = S.size();

		if (S[sz - 1] == 'h' && S[sz - 2] == 'c')
		{
			S += "es";
			cout << S << '\n';
			continue;
		}

		if (S.back() == 'f')
		{
			S.pop_back ();
			S += "ves";
			cout << S << '\n';
			continue;
		}

		if (S[sz - 1] == 'e' && S[sz - 2] == 'f')
		{
			S.pop_back ();
			S.pop_back ();
			S += "ves";
			cout << S << '\n';
			continue;
		}

		if (S.back() == 'y')
		{
			S.pop_back();
			S += "ies";
			cout << S << '\n';
			continue;
		}

		S += "s";
		cout << S << '\n';
	}

	return 0;
}