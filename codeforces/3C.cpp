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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> board(3);
    for(int i = 0; i < 3; i++) {
        cin >> board[i];
    }
    int cx = 0, cy = 0, cdot = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'X')
                cx++;
            else if(board[i][j] == '0')
                cy++;
            else
                cdot++;
        }
    }
    if(cx < cy || cx > cy + 1) {
        cout << "illegal\n"; return 0;
    }
    set<char> wins;
    for(int i = 0; i < 3; i++) {
        // row i, col i
        bool isrow = true, iscol = true;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != board[i][0])
                isrow = false;
            if(board[j][i] != board[0][i])
                iscol = false;
        }
        if(isrow) {
            if(board[i][0] == 'X' || board[i][0] == '0')
                wins.insert(board[i][0]);
        }
        if(iscol) {
            if(board[0][i] == 'X' || board[0][i] == '0')
                wins.insert(board[0][i]);
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '.')
        wins.insert(board[0][0]);
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '.')
        wins.insert(board[1][1]);
    if(wins.size() > 1) {
        cout << "illegal\n"; return 0;
    }
    if(wins.size() == 0) {
        if(cdot == 0) {
            cout << "draw\n"; return 0;
        }
        if(cx == cy) {
            cout << "first\n"; return 0;
        }
        else {
            cout << "second\n"; return 0;
        }
    }
    if(*wins.begin() == 'X') {
        if(cx == cy)
            cout << "illegal\n";
        else
            cout << "the first player won\n";
    }
    else {
        if(cx != cy)
            cout << "illegal\n";
        else
            cout << "the second player won\n";
    }
    return 0;
}
