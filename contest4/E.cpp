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

    ll N, a;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        ans += a * (N - i) * (i + 1);
    }
    cout << ans << '\n';
    return 0;
}