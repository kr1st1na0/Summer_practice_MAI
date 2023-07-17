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

struct cord {
    int x, y;
};

using grid = vector<string>;

bool check(int x, int y, int n, int m) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void bfs(const grid& g, cord u, vector< vector<int> >& d) {
    int n = g.size();
    int m = g[0].size();
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int x = u.x;
    int y = u.y;
    d[x][y] = 0;
    queue<cord> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        // x = u.x;
        // y = u.y;
        for (int i = 0; i < 4; ++i) {
            int xn = u.x + dx[i];
            int yn = u.y + dy[i];
            if (!check(xn, yn, n, m)) {
                continue;
            }
            if (g[xn][yn] == '#' || d[xn][yn] < INF) {
                continue;
            }
            d[xn][yn] = d[u.x][u.y] + 1;
            q.push({xn, yn});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    grid g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    cord start;
    cin >> start.x >> start.y;
    --start.x;
    --start.y;

    vector<vector<int>> d(n, vector<int>(m, INF)); 
    bfs(g, start, d);
    for (const vector<int>&row : d) {
        for (int elem : row) {
            cout << (elem == INF ? -1 : elem) << ' ';
        }
        cout << '\n';
    }
    return 0;
}