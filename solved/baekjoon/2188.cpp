// BOJ 2188
// 축사배정
// https://blog.naver.com/ndb796/221240613074
// https://pledge.tistory.com/entry/%EB%B0%B1%EC%A4%802188-%EC%B6%95%EC%82%AC-%EB%B0%B0%EC%A0%95
// 20201125


#include<iostream>
#include<vector>
#define MAX 200
 
using namespace std;

int n, m;
vector<int> g[MAX+5];
int conn[MAX+5] = {0, }; // conn[house_id] -> cow_id
bool vt[MAX+5];
int ans = 0;
 
void input() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        int len;
        cin >> len;
        for(int j=0; j<len; j++) {
            int tmp;
            cin >> tmp;
            g[i].push_back(tmp);
        }
    }
}
int dfs(int node) {
    vector<int> houses = g[node];
    for(int i=0; i<houses.size(); i++) {
        int tmp = houses[i];
        if(vt[tmp]) continue;
        vt[tmp] = true; // 열린 dfs 안에서만 통용 -> 비킬때 중복 방지

        if(conn[tmp] == 0 || dfs(conn[tmp])) { // 먹기 가능 or 비키기 가능
            conn[tmp] = node;
            return true;
        }
    }
    return false;
}
void solve() {
    for(int i=1; i<=n; i++) {
        fill(vt, vt+MAX, false);
        if(dfs(i)) ans++;
    }
}
void print() {
    cout << ans << endl;
}
 
int main() {
    input();
    solve();
    print();
 
    return 0;
} 
