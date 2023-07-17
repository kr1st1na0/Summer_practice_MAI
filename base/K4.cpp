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

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

bool dfs(int u, int prev, const graph& g, vector<int>& colour, 
        vector<int>& path, vector<int>& cycle) {
    if (colour[u] == BLACK) {
        return false;
    }
    if (colour[u] == GRAY) {
        return true;
    }
    colour[u] = GRAY;
    path.push_back(u);
    for (int v : g[u]) {
        if (v == prev) {
            continue;
        }
        bool tmp = dfs(v, u, g, colour, path, cycle);
        if (tmp && cycle.empty()) {
            int ind = path.size() - 1;
            cycle.push_back(v);
            while (path[ind] != v) {
                cycle.push_back(path[ind]);
                --ind;
            }
            return true;
        }
    }

    colour[u] == BLACK;
    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    graph g(n);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v); // ориентированный
        // неориентированный 
        g[v].push_back(u);
    }
    int start = 0; 
    vector<int> colour(n);
    vector<int> path;
    vector<int> cycle;
    dfs(start, -1, g, colour, path, cycle);
    sort(all(cycle));
    if (cycle.empty()) {
        cout << "No cycle\n";
    }
    else {
        for (int elem : cycle) {
            cout << elem + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}