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

    string expr;
    getline(cin, expr);
    stack<ll> st;
    int i = 0;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            st.push(expr[i] - '0');
        }
        else if (expr[i] != ' ') {
            ll op1 = st.top();
            st.pop(); 
            ll op2 = st.top();
            st.pop();
            ll result;

            if (expr[i] == '+') {
                result = op2 + op1;
            }
            else if (expr[i] == '-') {
                result = op2 - op1;
            }
            else if (expr[i] == '*') {
                result = op2 * op1;
            }
            st.push(result);
        }
        i++;
    }
    cout << st.top() << endl;
    return 0;
}