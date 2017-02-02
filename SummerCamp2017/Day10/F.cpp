#include <bits/stdc++.h>
using namespace std;

long long n;

bool solve ()
{
	if (n == 2)
		return true;

	long long curK = 2;
	long long curN = 2;
	long long add = 2;

	while (true)
	{
		curN += add;

		if (curK * curK <= curN)
		{
			add++;
			curN++;
			curK++;
		}

		if (curN == n)
			return true;

		if (curN > n)
			return false;

		if (n < curK * curK)
		{
			long long dif = n - curN;

			if ((dif % add) == 0)
				return true;
			

			return false;
		}
	}

	return false;
}

int main ()
{	
	ifstream cin ("nim.in");
	ofstream cout ("nim.out");

	cin >> n;

	if (solve ())
		cout << "LOSE\n";
	else
		cout << "WIN\n";

	return 0;
}