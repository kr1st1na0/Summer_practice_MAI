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
 
    int x1, y1, x2, y2, x3, y3, x4, y4, a, b, temp, s = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
 
    int s1, s2;
    int l_y1 = abs(y1 - y2); // 5
    int l_x1 = abs(x1 - x2); // 78
    int l_y2 = abs(y3 - y4); // 35
    int l_x2 = abs(x3 - x4); // 7
    s1 = l_y1 * l_x1;
    s2 = l_y2 * l_x2;
 
    if (x1 > x2){
        temp = x2;
        x2 = x1;
        x1 = temp;
    }
    if (x3 > x4){
        temp = x4;
        x4 = x3;
        x3 = temp;
    }
    if (y1 > y2){
        temp = y2;
        y2 = y1;
        y1 = temp;
    }
    if (y3 > y4){
        temp = y4;
        y4 = y3;
        y3 = temp;
    }
    if ((x2 < x3) || (x4 < x1) || (y2 < y3) || (y4 < y1)){
        cout << s1 + s2 <<endl;
    } else {
        a = min(x4,x2) - max(x1,x3);
        b = min(y4,y2) - max(y1,y3);
        s = s1 + s2 - a * b;
        if (s < 0) {
            cout << 0 << endl;
        } else {
        cout << s << endl;
        }
    }
    return 0;
}