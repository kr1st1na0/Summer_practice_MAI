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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    ll x, summ = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        summ += x;
    }
    cout << summ << endl;
    return 0;
}