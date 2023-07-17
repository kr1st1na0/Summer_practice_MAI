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

    int n, m, start, finish;
    cin >> n >> m >> start >> finish;
    graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i){
        sort(all(g[i]));
    }

    --start;
    --finish;
    vector<int> d, prev; 
    bfs(g, start, d, prev);

    if (d[finish] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    int currNode = finish;
    while (currNode != -1) {
        path.push_back(currNode);
        currNode = prev[currNode];
    }
    reverse(path.begin(), path.end());
    for (int elem : path) {
        cout << elem + 1 << ' ';
    }
    cout << endl;
    return 0;
}