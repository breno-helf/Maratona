#include <bits/stdc++.h>
using namespace std;

int const maxN = 1e5 + 10;
int const SIZE = 1e6 + 10;
int const N = 1e6 + 1;

typedef pair <int, int> pii;

int n, c[maxN];

vector <int> ans;

int lastPointer[maxN];

struct node
{
    int pos, maior;

    node ()
    {
        maior = 0;
        pos = -1;
    }

    void merge (node L, node R)
    {
        if (L.maior > R.maior)
        {
            maior = L.maior;
            pos = L.pos;
        }
        else
        {
            maior = R.maior;
            pos = R.pos;
        }
    }

} seg[4 * SIZE];

void update (int idx, int i, int j, int pos, int val, int P)
{
    if (i == j)
    {
        if (val > seg[idx].maior)
        {
            seg[idx].maior = val;
            seg[idx].pos = P;
        }

        return;
    }

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    if (pos <= mid)
        update (left, i, mid, pos, val, P);
    else
        update (right, mid + 1, j, pos, val, P);

    seg[idx].merge (seg[left], seg[right]);
}

node query (int idx, int i, int j, int ini, int fim)
{
    if (i > j || j < ini || fim < i)
        return node();

    if (ini <= i && j <= fim)
        return seg[idx];

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    node L = query (left, i, mid, ini, fim);
    node R = query (right, mid + 1, j, ini, fim);

    if (L.maior > R.maior)
        return L;

    return R;
}

int dp[maxN];

void solve ()
{   
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        lastPointer[i] = i;

        node Q;

        if (c[i] - 2 >= 1)
        {
            Q = query (1, 1, N, 1, c[i] - 2);

            if (Q.maior + 1 > dp[i])
            {
                dp[i] = Q.maior + 1;
                lastPointer[i] = Q.pos;
            }
        }

        if (c[i] + 2 <= N)
        {
            Q = query (1, 1, N, c[i] + 2, N);
        
            if (Q.maior + 1 > dp[i])
            {
                dp[i] = Q.maior + 1;
                lastPointer[i] = Q.pos;
            }
        }

        Q = query (1, 1, N, c[i], c[i]);

        if (Q.maior + 1 > dp[i])
        {
            dp[i] = Q.maior + 1;
            lastPointer[i] = Q.pos;
        }

        update (1, 1, N, c[i], dp[i], i);    
    }

    int answer = -1;
    int lastPositions = -1;

    for (int i = 1; i <= n; i++)
        if (answer < dp[i])
        {
            answer = dp[i];
            lastPositions = i;
        }

    while (true)
    {
        ans.push_back (lastPositions);

        if (lastPointer[lastPositions] == lastPositions)
            break;

        lastPositions = lastPointer[lastPositions];
    }

    reverse (ans.begin(), ans.end());
}

int main() 
{
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i]++;
    }

    solve ();

    cout << n - ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << c[ans[i]] - 1 << " ";
    cout << '\n';

    return 0;   
}
