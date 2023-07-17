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

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map<string, string> base;
    map<string, bool> on;
    int i = 0;
    string request, login, password;
    while (cin >> request) {
        if (request == "register") {
            cin >> login >> password;
            if (!base.count(login)) {
                base[login] = password;
                on[login] = false;
                cout << "account created\n";
            }
            else {
                cout << "login already in use\n";
            }
        }
        else if  (request == "login") {
            cin >> login >> password;
            if (!base.count(login) || base[login] != password) {
                cout << "wrong account info\n";
            }
            else if (on[login]) {
                cout << "already logged in\n";
            }
            else {
                on[login] = true;
                cout << "logged in\n";
            }
        }
        else if (request == "logout") {
            cin >> login;
            if (on[login]) {
                on[login] = false;
                cout << "logged out\n";
            }
            else {
                cout << "incorrect operation\n";
            }
        }
    }
    return 0;
}