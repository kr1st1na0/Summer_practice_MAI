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
    int pos, val;

    event() = default;

    event(int _pos, int _val) : pos(_pos), val(_val) {}
};

bool comp(const event& a, const event& b) {
    if (a.pos != b.pos) {
        return a.pos < b.pos;
    } 
    else {
        return a.val < b.val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        e.emplace_back(l, 1);
        e.emplace_back(r + 1, - 1);
    }
    sort(all(e), comp);
    int ans = 0;
    int cnt = 0;
    int last_pos = -1; 
    for (event elem : e) {
        cnt += elem.val;
        if (cnt > 0 && last_pos == -1) {
            last_pos = elem.pos;
        }
        if (cnt == 0) {
            int l = last_pos;
            int r = elem.pos - 1;
            int len = r - l + 1;
            ans += len;
            last_pos = -1;
        }
    }
    cout << ans << '\n';

    return 0;
}