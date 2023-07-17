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

string sumFunc(const string& num1, const string& num2) {
    string res;
    int len1 = num1.length(), len2 = num2.length();
    int maxLen = max(len1, len2);
    int d1, d2, los = 0;
    for (int i = 0; i < maxLen; i++) {
        if (i < len1) {
            d1 = num1[len1 - i - 1] - '0';
        } else { d1 = 0; }
        if (i < len2) {
            d2 = num2[len2 - i - 1] - '0';
        } else { d2 = 0; }

        int sum = d1 + d2 + los;
        los = sum / 10;
        int d = sum % 10;
        res.insert(res.begin(), d + '0');
    }
    if (los > 0) {
        res.insert(res.begin(), los + '0');
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string ans;
    string number;

    while (cin >> number) {
        number.erase(number.find('.'), 1);
        // cout << number << endl;
        ans = sumFunc(ans, number);
    }
    int len = ans.length();
    string result = ans.substr(0, len - 15) + '.' + ans.substr(len - 15);
    cout << result << endl;
    return 0;
}