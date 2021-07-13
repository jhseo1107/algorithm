// BOJ 2675
// 문자열 반복
// 20210712

#include<iostream>
#include<string>
#define MAX 1000

using namespace std;

int t;
char result[MAX+5][160+5];

int main(){
    //freopen("in.txt", "r", stdin)
    iostream::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;
    for(int i=0; i<t; i++) {
        int r; string s;
        cin >> r >> s;
        for(int j=0; j<s.size(); j++) {
            for(int k=0; k<r; k++) {
                result[i][j*r+k] = s[j];
            }
        }
    }
    for(int i=0; i<t; i++) cout << result[i] << endl;
}