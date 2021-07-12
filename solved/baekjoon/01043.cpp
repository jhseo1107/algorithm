// BOJ 1043
// 거짓말
// 20201118

#include<iostream>
#define MAX 50

using namespace std;

struct arraywrapper {
    int idx;
    int arr[MAX+5];
};

int n, m;
int partyidx[MAX+5];
int party[MAX+5][MAX+5];
arraywrapper partylist[MAX+5]; 

int knownidx;
int known[MAX+5];

int g[MAX+5][MAX+5];
int degree[MAX+5] = {0, };

arraywrapper group[MAX+5];
int ingroup[MAX+5]; // 그룹 : 그래프의 각 연결성분
int groupcnt = 0;
int ans = 0;

int knowngroup[MAX+5] = {0, };
int knownparty[MAX+5] = {0, };

void input() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> m;
    cin >> knownidx;
    for(int i=0; i<knownidx; i++) cin >> known[i];
    for(int i=0; i<m; i++) {
        cin >> partyidx[i];
        for(int j=0; j<partyidx[i]; j++) {
            cin >> party[i][j];
            partylist[party[i][j]].arr[partylist[party[i][j]].idx++] = i;
        }
    }
}
void solve() { 
    //Init graph
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            g[i][j] = 0;
        }
    }

    //Build graph
    for(int i=0; i<m; i++) {
        for(int j=0; j<partyidx[i]; j++) {
            for(int k=j+1; k<partyidx[i]; k++) {
                g[party[i][j]][degree[party[i][j]]++] = party[i][k];
                g[party[i][k]][degree[party[i][k]]++] = party[i][j];
            }
        }
    }
    
    //Init ingroup to not bfs twice
    for(int i=1; i<=n; i++) ingroup[i] = -1;

    //Run bfs for everybody
    for(int i=1; i<=n; i++) {       
        int vt[MAX+5] = {0, };
        if(ingroup[i] != -1) continue;
        int q[MAX+5];
        int f = 0, r = 0;
        q[r++] = i;
        ingroup[i] = groupcnt;
        vt[i] = 1;
        group[groupcnt].arr[group[groupcnt].idx++] = i;
        do {
            int pop = q[f++];
            for(int j=0; j<degree[pop]; j++) {
                int tmp = g[pop][j];
                if(vt[tmp]) continue;
                q[r++] = tmp;
                ingroup[tmp] = groupcnt;
                vt[tmp] = 1;
                group[groupcnt].arr[group[groupcnt].idx++] = tmp;
            }
        } while(f != r);
        groupcnt++;
    }

    //Get groups with known people
    for(int i=0; i<knownidx; i++) {
        if(knowngroup[ingroup[known[i]]]) continue;
        knowngroup[ingroup[known[i]]] = 1;
    }

    //Get known parties with known groups
    for(int i=0; i<groupcnt; i++) {
        if(!knowngroup[i]) continue;
        for(int j=0; j<group[i].idx; j++) {
            int tmp = group[i].arr[j];
            for(int k=0; k<partylist[tmp].idx; k++) {
                knownparty[partylist[tmp].arr[k]] = 1;
            }
        }
    }

    ans = m;
    //Result ans
    for(int i=0; i<m; i++) {
        if(knownparty[i]) ans--; 
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