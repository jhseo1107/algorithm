// BOJ 1229
// 빅뱅의 6번째 멤버
// 20201116

#include<iostream>
#define MAX 1000000

using namespace std;

int n;
int bbArr[MAX+5];
int dp[MAX+5];

void input() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
}
void solve() {
    // Generate big bang array
    int idx = -1, bbVal = 1, incrementVal = 1;
    while(true) {
        idx += 1;
        if(bbVal > n) break;
        bbArr[idx] = bbVal;
        incrementVal += 4;
        bbVal += incrementVal;
    }
    
    // Dynamic Programming
    // Init dp
    for(int i=0; i<=n; i++) dp[i] = MAX+5;

    dp[n] = 0;
    for(int i=n; i>0; i--) {
        for(int j=0; j<idx; j++) {
            if(i - bbArr[j] < 0) break;
            if(dp[i-bbArr[j]] > dp[i]+1) {
                dp[i-bbArr[j]] = dp[i]+1;
            } 
        }
    }
}
void print() {
    cout << dp[0] << endl;
}

int main() {
    input();
    solve();
    print();

    return 0;
}