#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    ll n, a, m, k, mod;
    cin >> n;
    cin >> a >> m >> k >> mod;
    vector<ll> cnt(mod, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[a];
        a = ((a * m) + k) % mod;
    }
    ll sum = 0;
    ll q = 0;
    for (int i = 0; i < n; ++i) {
        while (cnt[q] == 0) { 
            ++q;
        }
        sum += (q * (i + 1)) % MOD;
        cnt[q]--;
    }
    cout << sum % MOD << endl;
    return 0;
}