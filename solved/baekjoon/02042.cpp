// BOJ 2042
// 구간 합 구하기
// Special Thanks To. jhhan11@acmicpc.net
// 20210102

#include<iostream>
#include<vector>
#define MAX 1048576

using namespace std;

int n, m, k;
vector<long long>arr;
long long tree[MAX*4+5];

 
long long build_tree(int at, int from, int to) {
    if(from == to) {  // I am leaf!
        tree[at] = arr[from];
    } else {
        int mid = (from + to) / 2;
        tree[at] = build_tree(at * 2 + 1, from, mid) + build_tree(at * 2 + 2, mid+1, to);
    }
    return tree[at];
}
long long update_tree(int at, int where, long long value, int start, int end) {
    if(start == end) {
        long long diff = value - tree[at];
        tree[at] = value;
        return diff;
    } else {
        int mid = (start + end) / 2;
        long long result;
        if(where <= mid) {
            result = update_tree(at * 2 + 1, where, value, start, mid);
        } else if (where > mid) {
            result = update_tree(at * 2 + 2, where, value, mid+1, end);
        }
        tree[at] += result;
        return result;
    }
}
long long print_tree(int at, int from, int to, int start, int end) {
    if(from == start && to == end) {
        return tree[at];
    } else {
        int mid = (start + end) / 2;
        if(to <= mid) {
            return print_tree(at * 2 + 1, from, to, start, mid);
        } else if (from > mid) {
            return print_tree(at * 2 + 2, from, to, mid+1, end);
        } else {
            return print_tree(at * 2 + 1, from, mid, start, mid) + print_tree(at * 2 + 2, mid+1, to, mid+1, end);
        }
    }
}
void solve() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    build_tree(0, 0, n-1);

    for(int i=0; i<m+k; i++) {
        int tmp1;
        cin >> tmp1;
        if(tmp1 == 1) {
            int tmp2;
            long long tmp3;
            cin >> tmp2 >> tmp3;
            // Get segment tree index from arr index
            update_tree(0, tmp2-1, tmp3, 0, n-1);
        }
        if(tmp1 == 2) {
            int tmp2, tmp3;
            cin >> tmp2 >> tmp3;
            cout << print_tree(0, tmp2-1, tmp3-1, 0, n-1) << endl;
        }
    }
}
int main() {
    solve();
 
    return 0;
} 
