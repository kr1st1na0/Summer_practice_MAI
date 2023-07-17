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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>(n, INF));
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            ll w;
            cin >> w;
            g[u][v] = w;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
            }
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (g[u][v] < INF) {
                cout << g[u][v] << ' ';
            }
            else {
                cout << "inf";
            }
        }
        cout << '\n';
    }

    return 0;
}