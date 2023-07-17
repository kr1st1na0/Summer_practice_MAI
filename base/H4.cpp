#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e17;

struct event {
    int right, left;

    event() = default;

    event(int _right, int _left) : right(_right), left(_left) {}
};

bool comp(const event& a, const event& b) {
    if (a.right != b.right) {
        return a.right < b.right;
    } 
    else {
        return a.left < b.left;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<event> e;
    int l, r;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        e.emplace_back(r, l);
    }
    sort(all(e), comp);
    int cnt = 1;
    int last_pos = e[0].right; 
    for (event elem : e) {
        if (elem.left >= last_pos) {
            cnt++;
            last_pos = elem.right;
        }
    }
    cout << cnt << '\n';
    return 0;
}