#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
    ll a = 0, b = 0;

    char c = getchar();
    bool dot = 0;
    int afterzeroa = 0;
    while (c != ' ') {
        if (c == '.') {
            dot = true;
        } else {
            a = a*10 + (c - '0');
            if (dot) afterzeroa++;
        }

        c = getchar();
    }

    dot = false;
    int afterzerob = 0;
    c = getchar();
    while (c != ' ' && c != '\n') {
        if (c == '.') {
            dot = true;
        } else {
            b = b*10 + (c - '0');
            if (dot) afterzerob++;
        }

        c = getchar();
    }

    //cout << "afterzeroa " << afterzeroa << " afterzerob " << afterzerob << endl;

    while (afterzeroa > afterzerob) {
        b *= 10;
        afterzerob++;
    } 

    while (afterzerob > afterzeroa) {
        a *= 10;
        afterzeroa++;
    } 

    //cout << a << "/" << b << " == ";
    cout << a/b << endl;
}
