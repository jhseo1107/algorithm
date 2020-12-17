// BOJ 1135
// 뉴스 전하기
// 20201217

#include<iostream>
#include<stack>
#include<algorithm>

#define MAX 50
 
using namespace std;

int n;
int g[MAX+5][MAX+5];
int degree[MAX+5];
int ans = 0;

 
void input() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == -1) continue;
        g[tmp][degree[tmp]++] = i;
    }
}
int dfs(int node) {
    int maxTime[degree[node] + 5];
    if(degree[node] == 0) return 0;

    for(int i=0; i<degree[node]; i++) {
        maxTime[i] = dfs(g[node][i]);
    }

    // Add delay before comparision
    std::sort(maxTime, maxTime+degree[node]);
    // Delay: 1min, 2min, ..., degree[node]
    int max = -1;
    for(int i=0; i<degree[node]; i++) {
        maxTime[i] += (degree[node] - i);
        if(maxTime[i] > max) max = maxTime[i];
    }
    return max;
}
void solve() {
    ans = dfs(0);
}
void print() {
    cout << ans;
}
 
int main() {
    input();
    solve();
    print();
 
    return 0;
} 
