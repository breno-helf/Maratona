//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string digit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string decim[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string teen[]  = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string convertNumber(int n) {
    if (n < 10) return digit[n];

    int f = n / 10, s = n % 10;

    if (f == 1) return teen[s];
    if (s == 0) return decim[f];

    return (decim[f] + "-" + digit[s]);
}

    
int main() {
    int n;

    cin >> n;
    
    string s = convertNumber(n);
    cout << s << endl;
}

