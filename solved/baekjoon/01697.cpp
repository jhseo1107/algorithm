// BOJ 1697
// 숨바꼭질
// 20201011

#include<iostream>
#include<algorithm>
#include<queue>

#define MAX 100000

using namespace std;

struct _tuple {
    int val;
    int depth;
};

int sister;
int brother;

queue<_tuple> q;
int vt[MAX+5] = {0, };

int ans;

void input() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> sister >> brother;
}
void solve() {
    q.push({sister, 0});
    vt[sister] = 1;
    do {
        _tuple tmp = q.front();
        q.pop();

        int canVisit[3] = {tmp.val+1, tmp.val-1, tmp.val*2};
        for(int i=0; i<3; i++) {
            if(canVisit[i] > 100000) continue;
            if(canVisit[i] < 0) continue;
            if(vt[canVisit[i]]) continue;

            if(canVisit[i] == brother) {
                ans = tmp.depth+1;
                return;
            }
            
            q.push({canVisit[i], tmp.depth+1});
            vt[canVisit[i]] = 1;
        }
    } while(!q.empty());
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