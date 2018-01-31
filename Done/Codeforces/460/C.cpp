#include<bits/stdc++.h>
using namespace std;

const int MAX = 2123;

int n, m, k;
int cnt;
char grid[MAX][MAX];

int main() {
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &grid[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    int qtd = 0;
    for (int j = 0; j < min(k, m); j++) {
      if (grid[i][j] == '.') qtd++;
    }

    if (qtd == k) cnt++;
    
    for (int j = k; j < m; j++) {
      if (grid[i][j] == '.') qtd++;
      if (grid[i][j - k] == '.') qtd--;

      if (qtd == k) cnt++;
    }
  }

  for (int j = 0; j < m; j++) {
    int qtd = 0;
    for (int i = 0; i < min(k, n); i++) {
      if (grid[i][j] == '.') qtd++;
    }

    if (qtd == k) cnt++;

    for (int i = k; i < n; i++) {
      if (grid[i][j] == '.') qtd++;
      if (grid[i - k][j] == '.') qtd--;

      if (qtd == k) cnt++;
    }
  }

  if (k == 1) {
    cnt /= 2;
  }
  
  printf("%d\n", cnt);
}
