#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

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
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> medians;
    multiset<int> lst, rst;
    lst.insert(A[0]);
    medians.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        if (A[i] <= *lst.rbegin())
            lst.insert(A[i]);
        else
            rst.insert(A[i]);

        if (lst.size() > rst.size() + 1) {
            rst.insert(*lst.rbegin());
            lst.erase(prev(lst.end()));
        } else if (rst.size() > lst.size()) {
            lst.insert(*rst.begin());
            rst.erase(rst.begin());
        }
        medians.push_back(*lst.rbegin());
    }

    for (int i = 0; i < N; i++) {
        cout << medians[i] << '\n';
    }

    return 0;
}