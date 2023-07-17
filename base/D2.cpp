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

// bool comp(int x, int y) { return x > y; }
// sort(a.begin(), a.end(), comp);
// sort(all(a));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int count  = 0;
    for (int i = 0; i < N; i++){
        if (a[i] != a[i + 1]){
            count += 1;
        }
    } 
    cout << count <<endl;

    return 0;
}
