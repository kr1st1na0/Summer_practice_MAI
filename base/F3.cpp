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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<ll> c(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
    }
    vector<ll> dp(n + 1, INF);
    vector<int> prev(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0) {
                break;
            }
            // dp[i] = min(dp[i], c[i] + dp[i - j]);
            ll jump_j = dp[i - j] + c[i];
            if (jump_j <= dp[i]) {
                dp[i] = jump_j;
                prev[i] = i - j;
            }
        }
    }
    vector<int> res;
    int u = n;
    while (u > 0) {
        res.push_back(u);
        u = prev[u];
    }
    res.push_back(0);
    reverse(all(res));
    cout << dp[n] << endl;
    cout << res.size() << endl;
    for (int elem : res) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}