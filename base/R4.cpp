#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <assert.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long double ldbl;
typedef double dbl;
typedef long long ll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5;

// prefix tree
struct trie {
    struct node {
        map<char, int> go;
        int cnt;
        int dp;

        node() = default;
    };

    vector<node> data;

    int nodeCreate() {
        data.emplace_back();
        return data.size() - 1;
    }

    trie() {
        nodeCreate();
    }

    bool canGo(int u, char c) {
        return data[u].go.count(c);
    }

    int go(int u, char c) {
        return data[u].go[c];
    }

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            if (!canGo(u, c)) {
                data[u].go[c] = nodeCreate();
            }
            ++data[u].dp;
            u = go(u, c);
        }
        ++data[u].dp;
        ++data[u].cnt;
    }

    void erase(const string& s) {
        int u = 0;
        for (char c : s) {
            assert(canGo(u, c));
            assert(data[u].dp > 0);
            --data[u].dp;
            u = go(u, c);
        }
        assert(data[u].dp > 0);
        assert(data[u].cnt > 0);
        --data[u].dp;
        --data[u].cnt;
    }

    int count(const string& s) {
        int u = 0;
        for (char c : s) {
            if (!canGo(u, c)) {
                return 0;
            }
            u = go(u, c);
        }
        return data[u].cnt;
    }

    using item = pair<char, int>;

    string lexString(int k) {
        int u = 0;
        string s;
        while (1) {
            if (data[u].cnt >= k) {
                return s;
            }
            else {
                k -= data[u].cnt;
            }
            for (item elem : data[u].go) {
                char c = elem.first;
                int v = elem.second;
                if (data[v].dp < k) {
                    k -= data[v].dp;
                }
                else {
                    s.push_back(c);
                    u = v;
                    break;
                }
            }
        }
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    trie t;
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        if ('0' <= s[0] && s[0] <= '9') {
            int k = stoi(s);
            string res = t.lexString(k);
            cout << res << '\n';
            t.erase(res);
        } 
        else {
            t.insert(s);
        }
    }

    return 0;
}