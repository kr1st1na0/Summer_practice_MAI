#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef int64_t ll;

const ll INF = 1e17;

void solve() {
    int N;
    cin >> N;
    vector<int> money(N);
    for (int i = 0; i < N; ++i) {
        money[i] = 0;
    }
    while (N >= 5000) {
            N -= 5000;
            money[4] += 1;
        }
        while (N >= 1000) {
            N -= 1000;
            money[3] += 1;
        }
        while (N >= 500) {
            N -= 500;
            money[2] += 1;
        }
        while (N >= 200) {
            N -= 200;
            money[1] += 1;
        }
        while (N >= 100) {
            N -= 100;
            money[0] += 1;
        }
        for (int i = 0; i < 5; i++) {
            cout << money[i] << ' ';
        }
        cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}