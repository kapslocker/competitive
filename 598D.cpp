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


unordered_map<int, int> sum;

void dfs(vector<vector<int> > &grid, vector<string> &board, vector<vector<int> > &visited, int i, int j, int seg) {
    if(board[i][j] == '*')
        return;
    if(visited[i][j] != 0)
        return;
    visited[i][j] = seg;
    sum[seg] += grid[i][j];
    dfs(grid, board, visited, i - 1, j, seg);
    dfs(grid, board, visited, i + 1, j, seg);
    dfs(grid, board, visited, i, j - 1, seg);
    dfs(grid, board, visited, i, j + 1, seg);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, x, y;
    string s;
    cin >> n >> m >> k;
    vector<string> board(n);
    vector<vector<int> > grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '*')
                continue;
            int l = 0;
            if(i > 0 && board[i - 1][j] == '*')
                l++;
            if(i < n - 1 && board[i + 1][j] == '*')
                l++;
            if(j < m - 1 && board[i][j + 1] == '*')
                l++;
            if(j > 0 && board[i][j - 1] == '*')
                l++;
            grid[i][j] = l;
        }
    }
    int seg = 1;
    vector<vector<int> > visited(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dfs(grid, board, visited, i, j, seg);
            seg++;
        }
    }
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        x--; y--;
        cout << sum[visited[x][y]] << endl;
    }
    return 0;
}
