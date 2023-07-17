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
    
    int l, r;
    cin >> l >> r;
    vector<ll> dp(r + 1, 0);
    dp[1] = 1;
    for (int i = 1; i <= r; ++i) {
        if (dp[i] != 0) {
            for (int j = 2 * i; j <= r; j += i) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = l; i <= r; ++i) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}