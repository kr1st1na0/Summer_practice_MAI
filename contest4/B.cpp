#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>

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
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int max_num = a[i];
        ans += max_num;
        for (int j = i + 1; j < N; j++) {
            max_num = max(max_num, a[j]);
            ans += max_num;
        }
    }
    cout << ans << endl;
    
    return 0;
}