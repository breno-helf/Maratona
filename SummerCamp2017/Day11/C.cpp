#include <bits/stdc++.h>
using namespace std;

int const N = 4 * 3e4 + 10;

int n;

set <int> Set;
map <int, int> nodeM;
int total;

void compress ()
{
	for (auto it: Set)
		nodeM[it] = ++total;
}

int A[N], B[N], R[N], P[N];

long long ans;
vector <int> deleteEdges;

int par[N], sz[N];

int root (int v)
{
	if (par[v] == v)
		return v;

	return root (par[v]);
}

void merge (int x, int y)
{
	x = root (x);
	y = root (y);

	if (x == y)
		return;

	if (sz[y] > sz[x])
		swap (x, y);

	par[y] = x;
	sz[x] += sz[y];
}

struct edge
{	
	int a, b, r, p, id;
	edge (int a, int b, int r, int p, int id) : a(a), b(b), r(r), p(p), id(id) {}
};

bool operator < (edge A, edge B)
{
	return (A.r > B.r) || (A.r == B.r && A.p > B.p);
}

vector <edge> E;

void solve ()
{
	for (int i = 1; i <= total; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}

	for (int i = 1; i <= n; i++)
		E.push_back (edge (nodeM[A[i]], nodeM[B[i]], R[i], P[i], i));

	sort (E.begin(), E.end());

	vector <int> notInMSt, inMST;

	for (int i = 0; i < E.size(); i++)
	{
		int u = E[i].a;
		int v = E[i].b;

		int r = E[i].r;
		int p = E[i].p;

		int id = E[i].id;

		if (root(u) == root(v))
		{
			notInMSt.push_back (id);
			continue;
		}

		merge (u, v);
		ans += p;

		inMST.push_back (id);
	}

	for (int i = 0; i < notInMSt.size(); i++)
		deleteEdges.push_back (notInMSt[i]);

	for (int i = 0; i < inMST.size(); i++)
		deleteEdges.push_back (inMST[i]);
}

int main() 
{	

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i] >> B[i] >> R[i] >> P[i];

		Set.insert (A[i]);
		Set.insert (B[i]);
	}	

	compress ();
	solve ();

	cout << ans << '\n';
	for (int i = 0; i < deleteEdges.size(); i++)
		cout << deleteEdges[i] << " ";
	cout << '\n';

	return 0;
}