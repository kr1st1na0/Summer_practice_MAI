#include <iostream>
#include <set>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main(){
    int N, k = 0;
    string s;
    cin >> N;
    set <string> A;
    for (int i = 0; i < N; i++){
        cin >> s;
        sort(s.begin(), s.end());
        A.insert(s);
    }
    k = A.size();
    cout << k <<endl;
    return 0;
}