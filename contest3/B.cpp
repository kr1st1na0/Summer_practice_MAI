#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const long long A = 1e9 + 7;

    long long n, k, m;
    cin >> n >> k >> m;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    set<long long> danger;
    for (long long i = 0; i < m; ++i) {
        long long x;
        cin >> x;
        danger.insert(x);
    }

    for (long long i = 1; i <= n; ++i) {
        if (danger.count(i)) {
            continue;
        }
        for (long long j = 1; j <= k && i - j >= 0; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % A;
        }
    }
    cout << dp[n] << endl;
}