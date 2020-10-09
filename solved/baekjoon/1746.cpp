// BOJ 1746
// 듣보잡
// 20201010

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

#define MAX 500000

using namespace std;

int n,m;
string noSee[MAX+5];
string noHear[MAX+5];

int ansCnt = 0;
string ans[MAX+5];

void input() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    cin >> m;
    for(int i=0; i<n; i++) {
        cin >> noSee[i];
    }
    for(int i=0; i<m; i++) {
        cin >> noHear[i];
    }
}
void solve() {
    sort(noSee, noSee + n);
    sort(noHear, noHear + n);

    int seePtr = 0, hearPtr = 0;
    for(seePtr; seePtr < n; seePtr++) {
        string see = noSee[seePtr];
        while(hearPtr < m) {
            string hear = noHear[hearPtr];
            if(strcmp(see.c_str(), hear.c_str()) < 0) { // hear faster than see
                break;
            } else if (strcmp(see.c_str(), hear.c_str()) == 0) { // hear == see
                ans[ansCnt++] = hear;
                break;
            }
            hearPtr++;
        }
    }
}
void print() {
    cout << ansCnt << endl;
    for(int i=0; i<ansCnt; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    input();
    solve();
    print();

    return 0;
}