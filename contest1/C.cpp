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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll F1 = 0, F2 = 1, F = 0, flag = 0, i = 2;

    if (n == 0) {
        flag = 1;
        cout << 0 << endl;
    }
    else if (n == 1) {
        flag = 1;
        cout << 1 << endl;
    }
    else {
        while (F < INF) {
            F = F1 + F2;
            F1 = F2;
            F2 = F;
            if (F == n) {
                cout << i << endl;
                flag = 1;
            }
            ++i;
        }
    }
    if (flag == 0) {
        cout << -1 << endl;
    }
    return 0;
}