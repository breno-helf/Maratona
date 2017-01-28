#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int,int> t4;
const int MAXN = 1e6+2;
char s[MAXN];
int top[] = {0,0,0,0};
int cnt[] = {0,0,0,0};
int st[MAXN][4];
int last = -1;

inline bool isEmpty(int *cnt) {
	return (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0);
}

inline void push(int *cnt) {
	last++;
	st[last][0] = cnt[0];
	st[last][1] = cnt[1];
	st[last][2] = cnt[2];
	st[last][3] = cnt[3];
}

inline void get() {
	top[0] = st[last][0];
	top[1] = st[last][1];
	top[2] = st[last][2];
	top[3] = st[last][3];
}

inline bool empty() {
	return last == -1;
}

inline void pop() {
	last--;
}

int main()
{
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");

	int t;
	fscanf(in, "%d", &t);
	while (t--) {
		last = -1;
		fscanf(in, " %s", s);
		int n = strlen(s);
		for (int i = 0; i < n; i++) {
			switch(s[i]) {
				case '(': s[i] = 1; break;
				case '[': s[i] = 2; break;
				case '{': s[i] = 3; break;
				case '<': s[i] = 4; break;
				case ')': s[i] = -1; break;
				case ']': s[i] = -2; break;
				case '}': s[i] = -3; break;
				case '>': s[i] = -4; break;
			}
		}

		bool ans = true;
		for (int i = 0; i < n;) {
			cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
			for (int k = i+1; k <= n; k++) {
				cnt[abs((int) s[k-1]) - 1]++;
				if (k == n || s[i]*s[k] < 0) {
					if (s[i] > 0) {
						push(cnt);		
					} else {
						while (true) {
							if (isEmpty(cnt)) break;

							if (empty()) {
								ans = false;
								goto out;
							}

							get();
							pop();

							for (int j = 0; j < 4; j++) {
								if (cnt[j] <= top[j]) {
									top[j] -= cnt[j];
									cnt[j] = 0;
								} else {
									cnt[j] -= top[j];
									top[j] = 0;
								}
							}
						}

						if (!isEmpty(top)) {
							if (!isEmpty(cnt)) {
								ans = false;
								goto out;
							}
							push(top);
						}
					}
					i = k;
					break;
				}
			}
		}

		out: if (empty() && ans) {
			fprintf(out, "T\n");
		} else {
			fprintf(out, "NIL\n");
		}
	}
}