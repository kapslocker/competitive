#include <bits/stdc++.h>
using namespace std;

#define int long long


template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream &os, set<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class K, class X> ostream &operator<<(ostream& os, map<K,X> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve(int k, int n) {
    vector<vector<int> > mat(n, vector<int>(n, 0));
    int trace = 0, rows = 0, cols = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        unordered_set<int> seen;
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (seen.find(mat[i][j]) != seen.end()) {
                found = true;
                break;
            }
            seen.insert(mat[i][j]);
        }
        if (found)
            rows++;
    }

    for (int j = 0; j < n; j++) {
        unordered_set<int> seen;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (seen.find(mat[i][j]) != seen.end()) {
                found = true;
                break;
            }
            seen.insert(mat[i][j]);
        }
        if (found)
            cols++;
    }

    for (int i = 0; i < n; i++) {
        trace += mat[i][i];
    }
    cout << "Case #" << k + 1 << ": " << trace << " " << rows << " " << cols << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        solve(i, n);
    }
    return 0;
}
