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

bool check_row(vector<string> &board, int r, int j) {
    int m = board[0].size();
    int s = j;
    while(s >= 0 && board[r][s] == '.') s--;
    if(s >= 0 && board[r][s] == '#')    return false;
    s = j;
    while(s < m && board[r][s] == '.')  s++;
    if(s < m && board[r][s] == '#') return false;
    return true;
}

bool check_column(vector<string> &board, int i, int c) {
    int n = board.size();
    int s = i;
    while(s >= 0 && board[s][c] == '.') s--;
    if(s >= 0 && board[s][c] == '#')    return false;
    s = i;
    while(s < n && board[s][c] == '.')  s++;
    if(s < n && board[s][c] == '#') return false;
    return true;
}

int count(vector<string> &board, char move) {
    int n = board.size(), m = board[0].size();
    // horizontal moves
    int ans = 0;
    for(int i = 0; i < n; i++) {
        // pick row i
        for(int j = 0; j < m; j++) {
            if(board[i][j] != '.')
                continue;
            // empty space. check left, right for #
            bool is_free = check_row(board, i, j);
            if(!is_free)    continue;
            // free to move here.
            int start = j, end = j + 1;
            while(end < m && board[i][end] == '.') {
                board[i][end] = move;
                end++;
            }
            while(start >= 0 && board[i][start] == '.') {
                board[i][start] = move;
                start--;
            }
            char next;
            if(move == '0') next = '1';
            else next = '0';
            int temp = count(board, next);
            if(temp == 0) {
                ans++;
            }
            for(int idx = start + 1; idx < end; idx++)  board[i][idx] = '.';
        }
    }
    // vertical moves
    for(int j = 0; j < m; j++) {
        // pick column j
        for(int i = 0; i < n; i++) {
            if(board[i][j] != '.')  continue;
            bool is_free = check_column(board, i, j);
            if(!is_free)    continue;
            int start = i, end = i + 1;
            while(end < n && board[end][j] == '.') {
                board[end][j] = move;
                end++;
            }
            while(start >= 0 && board[start][j] == '.') {
                board[start][j] = move;
                start--;
            }
            char next;
            if(move == '0') next = '1';
            else    next = '0';
            int temp = count(board, next);
            if(temp == 0) {
                ans++;
            }
            for(int idx = start + 1; idx < end; idx++)  board[idx][j] = '.';
        }
    }
    return ans;
}

int solve(vector<string> &board) {
    return count(board, '0');
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int r, c;
        cin >> r >> c;
        vector<string> board(r);
        for(int i = 0; i < r; i++) {
            cin >> board[i];
        }
        int num = solve(board);
        cout << "Case #" << tt << ": " << num << endl;
    }
    return 0;
}
