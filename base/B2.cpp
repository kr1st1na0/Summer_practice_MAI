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

    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0) {
        cout << 1 << endl;
    }
    else if (x > 0 && y < 0) {
        cout << 4 << endl;
    }
    else if (x < 0 && y > 0) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }
    
    return 0;
}