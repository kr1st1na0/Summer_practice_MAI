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
    ll u;
    ll w;
};

using wgraph = vector<vector<wedge>>;
using item = pair<ll, ll>;

vector<ll> maxWidthPath(const wgraph& g, ll s) {
    ll n = g.size();
    vector<ll> maxx(n, 0);
    vector<char> visited(n, false);
    priority_queue<item> pq;

    pq.push({INF, s});
    maxx[s] = INF;
    while (!pq.empty()) {
        ll curW = pq.top().first;
        ll curN = pq.top().second;
        pq.pop();
        if (visited[curN]) {
            continue;
        }
        visited[curN] = true;

        for (wedge elem : g[curN]) {
            ll nextN = elem.u;
            ll w = elem.w;
            ll w2 = min(curW, w);
            if (w2 > maxx[nextN]) {
                maxx[nextN] = w2;
                pq.push({w2, nextN});
            }
        }
    }
    return maxx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m, s;
    cin >> n >> m >> s;
    --s;
    wgraph g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<ll> ans = maxWidthPath(g, s);
    for (ll elem : ans) {
        if (elem == INF || elem < 0) {
            cout << -1 << ' ';
        }
        else {
            cout << elem << " ";
        }
    }
    cout << endl;
    return 0;
}