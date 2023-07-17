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

struct wedge {
    int u, v;
    ll w;

    wedge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n, m, start;
    cin >> n >> m >> start;
    --start;
    vector<wedge> e;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        e.emplace_back(u, v, w);
    }
    vector<ll> dp(n, INF);
    dp[start] = 0;
    bool changed = true;
    for (int i = 0; i < n && changed; ++i) {
        changed = false;
        for (wedge& elem : e) {
            int u = elem.u;
            int v = elem.v;
            ll w = elem.w;
            if (dp[u] + w < dp[v]) {
                changed = true;
                dp[v] = dp[u] + w;
            }
        }
    }
    if (changed) {
        cout << "Negative cycle\n";
        return 0;
    }
    for (ll elem : dp) {
        if (elem < INF) {
            cout << elem << ' ';
        }
        else {
            cout << "inf" << ' ';
        }
    }
    cout << endl;

    return 0;
}