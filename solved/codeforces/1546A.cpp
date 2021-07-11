// Codeforces 1546A
// AquaMoon and Two Arrays
// 20210712

#include<iostream>
#include<vector>
#define MAX 100
 
using namespace std;
 
struct testcase {
    int cnt;
    int arr_a[MAX+5];
    int arr_b[MAX+5];
};
 
struct subtract {
    int idx;
    int val;
};
 
int n;
testcase cases[MAX+5];
 
void input() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
 
    cin >> n;
    for(int i=0; i<n; i++) {
        testcase tmp;
        cin >> tmp.cnt;
        for(int j=0; j<tmp.cnt; j++) {
            cin >> tmp.arr_a[j];
        }
        for(int j=0; j<tmp.cnt; j++) {
            cin >> tmp.arr_b[j];
        }
        cases[i] = tmp;
    }
}
 
void solve(int idx) {
    testcase t = cases[idx];
    
    int asum = 0, bsum = 0;
    int arr_subtract[MAX+5];
    int needed_changes = 0;
    vector<subtract> positives, negatives;
 
    for(int i=0; i<t.cnt; i++) {
        asum += t.arr_a[i];
        bsum += t.arr_b[i];
 
        arr_subtract[i] = t.arr_a[i]-t.arr_b[i];
        if(arr_subtract[i] > 0) {
            needed_changes += arr_subtract[i];
            positives.push_back({i, arr_subtract[i]});
        } else if (arr_subtract[i] < 0) {
            negatives.push_back({i, -arr_subtract[i]});
        }
    }
    
    if(asum != bsum) {
        cout << -1 << endl;
        return;
    }
 
    cout << needed_changes << endl;
 
    while(needed_changes != 0) {
        needed_changes--;
        cout << positives.back().idx+1 << " " << negatives.back().idx+1 << endl;
        (&negatives.back())->val--; (&positives.back())->val--;
        if(negatives.back().val == 0) negatives.pop_back();
        if(positives.back().val == 0) positives.pop_back();
    }
}
 
int main() {
    input();
    for(int i=0; i<n; i++) solve(i);
}