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
const int MAXN = 1e6;

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

    string s1, s2;
    cin >> s1;
    cin >> s2;
    string S = s2 + '#' + s1 + s1;
    vector<int> Z = Z_function(S);
    int min_i = 1e9;
    int ans;
    for (int i = 1; i < Z.size(); i++) {
        if (Z[i] == s1.size() && i < min_i) {
            min_i = i;
        }
    }
    ans = s1.size() - min_i + 1 + s2.size();
    if (ans <= s1.size()) {
        if (ans == s1.size()) {
            cout << 0 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}