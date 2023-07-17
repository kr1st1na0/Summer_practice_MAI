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

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(n);
    vector<int> path(n);
    int ans = 0;
    int ans_j = -1;
    for (int i = 0; i < n; ++i) {
        int dp_max = 0;
        int dp_max_j = -1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && dp[j] > dp_max) {
                dp_max = dp[j];
                dp_max_j = j;
            }
        }
        dp[i] = 1 + dp_max;
        path[i] = dp_max_j;
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i] > ans) {
            ans = dp[i];
            ans_j = i;
        }
    }
    int u = ans_j;
    vector<int> res;
    while (path[u] != -1) {
        res.push_back(u);
        u = path[u];
    }
    res.push_back(u);
    cout << ans << '\n';
    reverse(all(res));
    for (int elem : res) {
        cout << elem + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}