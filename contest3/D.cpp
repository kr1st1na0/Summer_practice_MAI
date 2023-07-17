#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef int64_t ll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dp[i][j];
        } 
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] += dp[i - 1][0];
    }
    for (int j = 1; j < m; ++j) {
        dp[0][j] += dp[0][j - 1];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i][j - 1] + dp[i][j]);
        } 
    }
    cout << dp[n - 1][m - 1]<< endl;
    return 0;
}