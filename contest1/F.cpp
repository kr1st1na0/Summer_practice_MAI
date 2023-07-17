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

const int INF = 1e9;

void solve() {
    int N, temp, ans = 0;
    cin >> N;
    vector<int> shelf(N);
    for (int i = 0; i < N; ++i) {
        cin >> shelf[i]; 
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (shelf[j] > shelf[j + 1]) {
                ++ans;
                temp = shelf[j];
                shelf[j] = shelf[j + 1];
                shelf[j + 1] = temp;
            }
        }
    }
    cout << ans << endl;
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