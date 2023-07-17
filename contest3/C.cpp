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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> good(n + 1, vector<int>(m + 1, 1));
    int i, j;
    for (int p = 0; p < k; ++p) {
        cin >> i >> j;
        good[i][j] = 0;
    }  

    dp[0][0] = 1;
    for (int j = 1; j <= m; ++j) {
        if (!good[0][j]) {
            break;
        }
        dp[0][j] = dp[0][j - 1] + dp[0][j];
    }
    for (int i = 1; i <= n; ++i) {
        if (!good[i][0]) {
            break;
        }
        dp[i][0] = dp[i - 1][0] + dp[i][0];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!good[i][j]) {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        } 
    }
    cout << dp[n][m] << endl;
    return 0;
}