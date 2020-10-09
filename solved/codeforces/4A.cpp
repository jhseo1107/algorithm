// Codeforces 4A
// Watermelon
// 20201009

#include<iostream>

int num;
bool ans;

using namespace std;

void input() {
    cin >> num;
}
void solve() {
    if(num % 2 == 1) {
        ans = false;
        return;
    }
    if(num == 2) {
        ans = false;
        return;
    }
    ans = true;
}
void print() {
    if(ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    input();
    solve();
    print();
}