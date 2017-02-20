#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x);

#define SIZE 100000
#define V1 499
#define V2 500

vector <int> v[100001], le[100001];
int lev[100001], par[100001], p[100001];
int mark[100001];

void dfs(int x, int l)
{
	lev[x] = l;
	int a = (l + V1) / V2;
	a = V2 * a - V1;
	if (a == l) {
		p[x] = x;
	} else {
		p[x] = p[par[x]];
	}
	for (int i = 0; i < v[x].size(); ++i) {
		dfs(v[x][i], l+1);
	}
}

int main()
{
	int t, n, m, i, j, k, x, a, b, c, y, z, r;

	scan(t);
	while (t--) {
		scan(n);
		for (i = 1; i <= SIZE; ++i) {
			v[i].clear();
			p[i] = par[i] = mark[i] = 0;
		}

		for (i = 1; i <= n; ++i) {
			scan(x);
			scan(y);
			mark[x] = 1;
			if (y == 0) r = x;
			else v[y].pb(x);
			par[x] = y;
		}

		dfs(r, 1);
		//for (i = 1; i <= 10; ++i) cout << p[i] << " "; cout << endl;

		scan(m);
		while (m--) {
			scan(a);
			if (a == 0) {
				scan(y); scan(x);
				par[x] = y;
				mark[x] = 1;
				a = lev[x] = lev[y] + 1;
				b = (a + V1) / V2;
				b = V2 * b - V1;
				if (a == b) {
					p[x] = x;	
				} else {
					p[x] = p[par[x]];
				}
				//cout << x << " " << p[x] << endl;
			} else if (a == 1) {
				scan(x);
				mark[x] = 0;
			} else {
				scan(x); scan(k);
				if (mark[x] == 0) {
					cout << 0 << endl; continue;
				}
				a = lev[x] - k;
				if (a < 1) {
					cout << 0 << endl; continue;
				}
				b = lev[x];
				while (b != a) {
					if (p[x] == x || b-V1 < a) {
						x = par[x];
						b--;
					} else {
						x = p[x];
						b = lev[x];
					}
				}
				cout << x << endl;
			}
		}
	}

	return 0;
}
