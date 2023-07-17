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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N + 1);
    vector<ll> p(N + 1);
    while (Q--) {
        ll l, r, v;
        cin >> l >> r >> v;
        p[l] += v;
        if (r < N) {
            p[r + 1] -= v;
        }
    }
    for (int i = 1; i < N + 1; ++i) {
        a[i] = a[i - 1] + p[i];
    }

    for (int i = 1; i < N + 1; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}