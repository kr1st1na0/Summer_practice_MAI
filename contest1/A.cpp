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

void reverse(vector<int>& A, int l, int r) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int l, r, tmp;
    while (cin >> l >> r) {
        if (l == 0 && r == 0) { break; }
        l -= 1;
        r -= 1;
        while (l < r) {
            swap(A[l], A[r]);
            l += 1;
            r -= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}