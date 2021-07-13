// BOJ 2562
// 최댓값
// 20210712

#include<iostream>

using namespace std;

int maxval = 0;
int maxcnt;

int main(){
    //freopen("in.txt", "r", stdin)
    iostream::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i=0; i<9; i++) {
        int tmp;
        cin >> tmp;
        if(tmp > maxval) {
            maxval = tmp;
            maxcnt = i+1;
        }
    }
    cout << maxval << endl << maxcnt << endl;
}