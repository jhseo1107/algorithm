// BOJ 1008
// A/B
// 20210712

#include<iostream>

using namespace std;

int a,b;
long double ans;

int main(){
    //freopen("in.txt", "r", stdin)
    iostream::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> a;
    cin >> b;
    
    ans = (double)a / b;
    cout.precision(10);
    cout << ans << endl;
    return 0;
}