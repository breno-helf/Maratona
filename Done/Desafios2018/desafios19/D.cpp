#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string numbers[] = { "xxxxxx...xx...xx...xx...xx...xxxxxx",  "....x....x....x....x....x....x....x","xxxxx....x....xxxxxxx....x....xxxxx","xxxxx....x....xxxxxx....x....xxxxxx","x...xx...xx...xxxxxx....x....x....x","xxxxxx....x....xxxxx....x....xxxxxx","xxxxxx....x....xxxxxx...xx...xxxxxx","xxxxx....x....x....x....x....x....x","xxxxxx...xx...xxxxxxx...xx...xxxxxx","xxxxxx...xx...xxxxxx....x....xxxxxx",".......x....x..xxxxx..x....x......." };

map<string, int> M;

vector<string> el;

string s[7];

void buildPrint(ll num) {
    vector<int> dig;
    ll g = num;
    while (g > 0) {
        dig.push_back(g % 10);
        g /= 10;
    }

    reverse(dig.begin(), dig.end());

    for (int i = 0; i < 7; i++) {
        s[i] = "";
        for (int d : dig) {
            for (int k = 0; k < 5; k++) {
                s[i] += numbers[d][k + 5 * i];
            }
            s[i] += ".";
        }
        s[i].pop_back();
    }
}

int main() {
    for (int i = 0; i < 11; i++) {
        M[numbers[i]] = i;
        //cout << numbers[i] << " " << i << '\n';
    }
    
    
    for (int i = 0; i < 7; i++) {
        cin >> s[i];
        int n = s[i].size();
        string r = "";
        int j = 0;
        for (int k = 0; k < n; k++) {
            if (r.size() == 5) {
                if (i == 0) el.push_back(r);
                else el[j++] += r;
                r = "";                
            } else {
                r += s[i][k];
            }
        }
        if (i == 0) el.push_back(r);
        else el[j++] += r;
    }

    ll cur = 0;
    ll sum = 0;
    
    for (string e : el) {
        if (M[e] == 10) {
            sum += cur;
            cur = 0;
        } else cur = 10 * cur + M[e];      
    }
    sum += cur;

    buildPrint(sum);

    for (int i = 0; i < 7; i++) {
        cout << s[i] << '\n';
    }
    
    return 0;
}
