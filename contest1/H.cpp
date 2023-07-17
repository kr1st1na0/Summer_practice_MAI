#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int i_max, i_min;
    int maxx = -1e9;
    int minn = 1e9;
    int count_locMax = 0, count_locMin = 0;
    vector<int> locMax, locMin;
    if (N != 1) {
        for (int i = 0; i < N; ++i) {
            if (a[i] > maxx) { maxx = a[i]; i_max = i; }
            if (a[i] < minn) { minn = a[i]; i_min = i; }
        }

        if (a[0] < a[1]) {
            ++count_locMin;
            locMin.push_back(0);
        }
        else if (a[0] > a[1]) {
            ++count_locMax;
            locMax.push_back(0);
        }
        if (a[N - 1] < a[N - 2]) {
            ++count_locMin;
            locMin.push_back(N - 1);
        }
        else if (a[N - 1] > a[N - 2]) {
            ++count_locMax;
            locMax.push_back(N - 1);
        }

        for (int i = 1; i < N - 1; ++i) {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
                ++count_locMin;
                locMin.push_back(i);
            }
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ++count_locMax;
                locMax.push_back(i);
            }          
        }
        sort(all(locMin));
        sort(all(locMax));
        cout << count_locMin << ' ';
        for (int i = 0; i < locMin.size(); ++i) {
            cout << locMin[i] + 1 << ' ';
        }
        cout << '\n' << count_locMax << ' ';
        for (int i = 0; i < locMax.size(); ++i) {
            cout << locMax[i] + 1 << ' ';
        }
        cout << '\n' << i_min + 1 << ' ' << i_max + 1 << '\n';
    }
    else {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 1 << '\n';
    }

    return 0;
}