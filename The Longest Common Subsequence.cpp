#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int dp[1001][1001];
pair <int, int> par[1001][1001];
int a[1001], b[1001];
stack <int> st;

int main()
{
	int n, m, i, j, k, c, x, y, z;	
	cin >> n >> m;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= m; ++i) cin >> b[i];

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
                		par[i][j] = mkp(i-1, j-1);
			} else if (dp[i-1][j] > dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
				par[i][j] = mkp(i-1, j);
			} else {
				dp[i][j] = dp[i][j-1];
				par[i][j] = mkp(i, j-1);
			}
		}
	}
    
	i = n;
	j = m;
	while (i != 0 && j != 0) {
		x = par[i][j].first;
		y = par[i][j].second;
		if (x == i-1 && y == j-1) {
		    st.push(a[i]);
		}
		i = x;
		j = y;
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
    
	return 0;
}
