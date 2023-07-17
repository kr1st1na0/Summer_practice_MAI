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

const int INF = 1e9;
const ll MOD = 1e9 + 7;

using graph = vector< vector<int> >;

void bfs(const graph& g, int u, vector<int>& d, vector<int>& prev) {
    int n = g.size();
    d.assign(n, INF);
    prev.assign(n, -1);
    d[u] = 0;
    // prev[u] = -1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] != INF) {
                continue;
            }
            prev[v] = u;
            d[v] = d[u] + 1;
            q.push(v);
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v); // ориентированный
        // неориентированный 
        g[v].push_back(u);
    }
    int start = k - 1;
    vector<int> d, prev; 
    bfs(g, start, d, prev);
    for (int elem : d) {
        if (elem == INF) {
            cout << -1 << ' ';
        }
        else {
            cout << elem << ' ';
        }
    }
    cout << endl;
    return 0;
}