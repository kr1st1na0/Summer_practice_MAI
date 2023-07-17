#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    int i = 0, count = 0;
    string s1, s2;
    cin >> n >> m;
    cin >> s1;
    cin >> s2;
    while ((i = s1.find(s2,i)) != s1.npos){
        ++count;
        ++i;
    }
    cout << count <<endl;
    return 0;
}