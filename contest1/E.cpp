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

    string n;
    int count = 0;
    cin >> n;

    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == '0') {
            count += 1;
        }
        else if (n[i] == '4') {
            count += 1;
        }
        else if (n[i] == '6') {
            count += 1;
        }
        else if (n[i] == '8') {
            count += 2;
        }
        else if (n[i] == '9') {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}