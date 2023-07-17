#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll f = INF, s = INF, t = INF;
        if (i % 2 == 0 && i / 2 >= 1) {
            f = dp[i / 2] + i; 
        } 
        if (i % 3 == 0 && i / 3 >= 1) {
            s = dp[i / 3] + i;
        }
        t = dp[i - 1] + i;
        dp[i] = min({f, s, t});
    }
    cout << dp[n] - 1 << endl;

    return 0;
}