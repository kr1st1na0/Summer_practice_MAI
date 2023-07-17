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
const int MAXN = 1e8;

using graph = vector< vector<int> >;

vector<char> visited;

bool dfs(int u, int f, const graph& g, vector<int>& path) {
    if (visited[u]) {
        return false;
    }
    visited[u] = true;
    path.push_back(u);
    if (u == f) {
        return true;
    }
    for (int v : g[u]) {
        bool tmp = dfs(v, f, g, path);
        if (tmp) {
            return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, f;
    cin >> n >> m >> s >> f;
    graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    --s;
    --f;
    visited.resize(n, 0);
    vector<int> path;
    bool ans = dfs(s, f, g, path);
    if (!ans) {
        cout << "-1\n";
    }
    else {
        for (int el : path) {
            cout << el + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}