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

vector<int> Z_function(const string s) {
    int n = s.size();
    vector<int> Z(n);
    Z[0] = n;
    int l = -1, r = -1;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            Z[i] = min(Z[i - l], r - i);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
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

    string s;
    cin >> s;
    vector<int> Z = Z_function(s);
    for (int elem : Z) {
        cout << elem << ' ';
    }
    cout << endl;

    return 0;
}