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
const int MAXN = 2 * 1e5;

using graph = vector< vector<int> >;

int component[MAXN];

void dfs(const graph& g, int v, int ans_count) {
    component[v] = ans_count;
    for (int u : g[v])
        if (!component[u])
            dfs(g, u, ans_count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans_count = 0;
    for (int i = 0; i < n; i++)
    if (!component[i]) {
        dfs(g, i, ++ans_count);
    }
    cout << ans_count << endl;
    return 0;
}
