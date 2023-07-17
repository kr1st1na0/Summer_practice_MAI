#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
struct item {
    string name;
    int s;
    int p;
};
bool cmp (item x, item y){
    if (x.s != y.s){
        return x.s > y.s;
    }
    else if ((x.s == y.s) && (x.p != y.p)){
        return x.p < y.p;
    }
    else if ((x.s == y.s) && (x.p == y.p)){
        return x.name < y.name;
    }
    else {
        return 0;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
 
    vector <item> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i].name >> a[i].s >> a[i].p;
    }   
 
    sort(a.begin(), a.end(),cmp);
    for (int i = 0; i < N; i++){
        cout << a[i].name << '\n';
    } 
    return 0;
}