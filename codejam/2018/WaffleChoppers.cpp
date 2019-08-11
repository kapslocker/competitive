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


bool solve(vector<string> &board, int H, int V) {
    int n = board.size(), m = board[0].size();
    vector<vector<int> > pre(n, vector<int>(m, 0));
    vector<vector<int> > rsum(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '@') {
                rsum[i][j]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int prev;
            if(i == 0)  prev = 0;
            else    prev = pre[i-1][j];
            pre[i][j] = prev + rsum[i][j];
        }
    }
    for(int s = 0; s < n; s++) {
        for(int t = 0; t < m; t++) {
            int count = pre[s][t];
            bool ispossible = false;
            for(int )
        }
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int r, c, v, h;
        cin >> r >> c >> >> h >> v;
        vector<string> board(r);
        for(int i = 0; i < r; i++) {
            cin >> board[i];
        }
        bool ans = solve(board, h, v);
        string resp = ans == 1 ? "POSSIBLE" : "IMPOSSIBLE";
        cout << "Case #" << tt << ": " << resp << endl;
    }
    return 0;
}
