#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main() {
  int n;
  double m;
  double a, b;
  double ratio = 1e9;

  cin >> n >> m;
  
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ratio = min(ratio, a/b);
  }

  cout << fixed << setprecision(8) << ratio * m << endl;
}
