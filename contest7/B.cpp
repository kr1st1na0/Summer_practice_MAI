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
const int MAXN = 1e5;

vector<int> Z_function(const string& S) {
    int n = S.size();
    vector<int> Z(n);
    Z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            Z[i] = min(Z[i - l], r - i);
        }
        while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]]) {
            ++Z[i];
        }
        if (i + Z[i] > r) {
            l = i;
            r = i + Z[i];
        }
    }
    return Z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int n = S.length();
    int ans = n;
    vector<int> Z = Z_function(S);
    for (int i = 1; i < n; ++i) {
        if (Z[i] == n - i && n % i == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}