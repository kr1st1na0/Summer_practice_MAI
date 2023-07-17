#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef int64_t ll;

const ll INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll N, a;
    cin >> N;
    if (N > 1) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < N; ++i) {
            cin >> a;
            q.push(a);
        }
        ll a1, a2;
        while (q.size() != 1) {
            ll a1 = q.top();
            q.pop();
            ll a2 = q.top();
            q.pop();
            cout << a1 << ' ' << a2 << '\n';
            q.push(a1 + a2);
        }
    }
    return 0;
}