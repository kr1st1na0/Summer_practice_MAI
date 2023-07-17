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
typedef long long ll;

const ll INF = 1e17;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, p = 1, ans = 0;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        p = (p * 2) % MOD;
    }
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            a[i] += MOD;
        }
    }
    for (ll i = 0; i < N; ++i) {
        ans = (ans + a[i]) % MOD;
    }

    ans = (ans * p) % MOD;
    cout << ans << '\n';
    return 0;
}