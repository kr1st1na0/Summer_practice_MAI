#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

using graph = vector< vector<int> >;

vector<char> visited;
vector<int> longPath;

void dfs(const graph& g, int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) { dfs(g, v); }
        if (longPath[v] + 1 > longPath[u]) {
            longPath[u] = longPath[v] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    graph g(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    visited.resize(N + 1, false);
    longPath.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(g, i);
        }
    }
    int maxLength = 0;
    int node = 0;
    for (int i = 1; i <= N; i++) {
        if (longPath[i] > maxLength) {
            maxLength = longPath[i];
            node = i;
        }
    }
    vector<int> path;
    while (maxLength > 0) {
        path.push_back(node);
        maxLength--;
        for (int u : g[node]) {
            if (longPath[u] == maxLength) {
                node = u;
                break;
            }
        }
    }
    path.push_back(node);
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == 0 && path.size() == 1) {
            cout << 1;
            break;
        }
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}