#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <assert.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e6;

const ll B = 31;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<ll> b_pow(MAX_N + 1);
    b_pow[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        b_pow[i] = (b_pow[i - 1] * B) % MOD;
    }

    string S, P;
    cin >> P;
    cin >> S;
    
    int n = S.size();
    int m = P.size();
    int ans = 0;
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = (pref[i - 1] * B + (S[i - 1] - 'a' + 1)) % MOD;
    }
    ll hp = 0;
    for (int i = 0; i < m; ++i) {
        hp = (hp * B + P[i] - 'a' + 1) % MOD;
    }

    for (int i = 0; i < n - m + 1; ++i) {
        int l = (i) + 1;
        int r = (i + m - 1) + 1;
        ll h_sub = (pref[r] - (pref[l - 1] * b_pow[m]) % MOD) % MOD;
        if (h_sub < 0) {
            h_sub += MOD;
        }
        if (h_sub == hp) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}