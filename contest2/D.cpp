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
typedef long long ll;

const ll INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll N, a0;
    cin >> N >> a0;
    ll A, s = 1;
    ll max1 = -1e9;
    ll max2 = -1e9; 
    
    for (int i = 0; i < N; ++i) {
        s = (s * 5) % INF;
        A = a0 * s % INF;
        if (A > max1) {
            max2 = max1;
            max1 = A;
        }
        else if (A > max2) {
            max2 = A;
        }
    }
    cout << max2 << ' ' << max1 << endl;
    return 0;
}