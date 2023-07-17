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
typedef int64_t ll;

const ll INF = 1e17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(all(A));
    vector <int> B(N);
    if (N == 1){
        cout << "Deck looks good" << endl;
        return 0;
    }
    for (int i = 1; i < N; i++){
        if ((A[i] - A[i - 1]) != 1){
            cout << "Scammed" << endl;
            return 0;
        }
    }
    cout << "Deck looks good" << endl;
    return 0;
    return 0;
}