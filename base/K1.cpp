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

/*
// simple
void dfs(int u, const graph& g, vector<int>& visited) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    cout << u + 1 << endl;
    for (int v : g[u]) {
        dfs(v, g, visited);
    }
}
*/

vector<int> cnt;
vector<char> visited;

void dfs(int u, int prev, const graph& g, int& counter) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    cnt[u] = counter;
    ++counter;
    for (int v : g[u]) {
        if (v != prev) {
            dfs(v, u, g, counter);
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
    cnt.resize(n, -1);
    visited.resize(n, 0);
    int counter = 0;
    dfs(start, start, g, counter);
    for (int el : cnt) {
        cout << el << ' ';
    }
    cout << endl;
    return 0;
}