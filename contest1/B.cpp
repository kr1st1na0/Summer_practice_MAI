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

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = fact * i % INF;
    }
    cout << fact << endl;
    return 0;
}