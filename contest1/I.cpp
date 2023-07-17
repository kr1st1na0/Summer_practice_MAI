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

const ll INF = 1e17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    string N;
    cin >> N;
    string res;

    ll N10 = 0;
    int d;
    int i = N.length() - 1;
    for (char elem : N) {
        if (elem >= '0' && elem <= '9') {
            d = elem - '0';
        }
        else {
            d = elem - 'a' + 10;
        }
        N10 = N10 * A + d;
    }
    if (N10 == 0) {
        res = "0";
    }
    while (N10 != 0) {
        int digit = N10 % B;
        if (digit < 10) {
            res.push_back(char(digit + '0'));
        }
        else {
            res.push_back(char(digit + 'a' - 10));
        }
        N10 /= B;
    }
    reverse(all(res));
    cout << res << '\n';
    return 0;
}