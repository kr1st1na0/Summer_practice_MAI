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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(all(A));
    ll count = 0;
    for (int a = 0; a < N - 2; ++a) {
        for (int b = a + 1; b < N - 1; ++b) {
            if (A[a] > 0 && A[b] > 0) {
                ll c = A[a] + A[b];
                auto p = lower_bound(A.begin() + b + 1, A.end(), c);
                count += distance(A.begin() + b + 1, p);
            }
        }
    }
    cout << count << endl;
    return 0;
}