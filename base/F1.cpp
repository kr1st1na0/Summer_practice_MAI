#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const long long A = 1e9 + 7;

    long long n, k;
    cin >> n >> k;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= k && i - j >= 0; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % A;
        }
    }
    cout << dp[n] << endl;
}