// BOJ 1107
// 리모컨
// https://www.acmicpc.net/board/view/46120 의 도움을 받음. (4번 반례) 
// 20201007

#include<iostream>
#include<cmath>

using namespace std;

int targetChn;
int currentChn = 100;

int unableNum[10];
int unableCnt;

bool isAble[10];

int ans;

void input() {
    //freopen("in.txt", "r", stdin);

    cin >> targetChn;
    cin >> unableCnt;

    fill_n(isAble, 10, true);
    for(int i=0; i<unableCnt; i++) {
        cin >> unableNum[i];
        isAble[unableNum[i]] = false;
    }
}
bool isNumSafe(int num) {
    if(num == 0) return isAble[0];

    int split[7]; // Split given num
    for(int i=5; i>=0; i--) {
        int tmp = round(pow(10, i)); //-> float problem : 100 == 99.99999
        split[5-i] = num / tmp;
        num = num % tmp;
    }

    bool stillZeroFlag = true; // Zeros in front of integer
    for(int i=0; i<6; i++) {
        int tmp = split[i];
        if(tmp == 0 && stillZeroFlag) continue;
        stillZeroFlag = false;

        if(!isAble[split[i]]) return false;
    }    
    return true;
}
int getNumLen(int num) {
    if(num == 0) return 1;

    int split[7]; // Split given num
    for(int i=5; i>=0; i--) {
        int tmp = round(pow(10, i)); //-> float problem : 100 == 99.99999
        split[5-i] = num / tmp;
        num = num % tmp;
    }

    bool stillZeroFlag = true; // Zeros in front of integer
    int ansNumLen = 0;
    for(int i=0; i<6; i++) {
        int tmp = split[i];
        if(tmp == 0 && stillZeroFlag) continue;
        stillZeroFlag = false;
        ansNumLen = 6 - i > ansNumLen ? 6 - i : ansNumLen;
    }
    return ansNumLen;
}
void solve() {
    if(unableCnt == 10) { // Exception : use only + -
        ans = std::abs(targetChn - currentChn);
        return;
    }

    // Go bottom
    int ptr = targetChn;
    int biggestBottom = -1;
    while(ptr >= 0) {
        if(isNumSafe(ptr)) { // Might not appear
            biggestBottom = ptr;
            break;
        }
        ptr--;
    }
    // Go top
    ptr = targetChn;
    int smallestTop = -1;
    while(true) {
        if(isNumSafe(ptr)) { // Must appear because unableCnt==10 exception is caught
            smallestTop = ptr;
            break;
        }
        ptr++;
    }

    int simpleAns = std::abs(targetChn - currentChn); // Use only + -
    int topAns = getNumLen(smallestTop) + std::abs(smallestTop - targetChn);

    ans = simpleAns < topAns ? simpleAns : topAns;
    if (biggestBottom != -1) { // Check Bottom
        int bottomAns = getNumLen(biggestBottom) + std::abs(biggestBottom - targetChn);
        ans = ans < bottomAns ? ans : bottomAns;
    }
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