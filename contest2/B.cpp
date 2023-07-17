#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef int64_t ll;

const ll INF = 1e17;

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
    int count = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int m = j + 1; m < N; ++m) {
                if (A[i] > 0 && A[j] > 0 && A[m] > 0 && A[i] + A[j] > A[m] && A[j] + A[m] > A[i] && A[i] + A[m] > A[j]) {
                    ++count;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}