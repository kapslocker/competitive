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

bool turn(vector<string> &board, vector<set<pair<int, int> > > &active, int p, int s) {
    int n = board.size(), m = board[0].size();
    bool canmove = false;
    set<pair<int, int> > newset;
    for(auto &poss: active[p]) {
        queue<pair<int, int> > st;
        st.push(poss);
        map<pair<int, int>, int> visited;
        visited[poss] = s;
        int times = 0;
        while(!st.empty()) {
            times++;
            pair<int, int> pos = st.front();
            st.pop();
            int ss = visited[pos];
            if(ss == 0) {
                newset.insert(pos);
                continue;
            }
            int i = pos.first, j = pos.second;
            char ch = '0' + p;
            if(i - 1 >= 0 && board[i - 1][j] == '.' && visited.find({i - 1, j}) == visited.end()) {
                board[i - 1][j] = ch;
                pair<int, int> temp = {i - 1, j};
                st.push(temp);
                visited[temp] = ss - 1;
            }
            if(i + 1 < n && board[i + 1][j] == '.' && visited.find({i + 1, j}) == visited.end()) {
                board[i + 1][j] = ch;
                pair<int, int> temp = {i + 1, j};
                st.push(temp);
                visited[temp] = ss - 1;
            }
            if(j - 1 >= 0 && board[i][j - 1] == '.' && visited.find({i, j - 1}) == visited.end()) {
                board[i][j - 1] = ch;
                pair<int, int> temp = {i, j - 1};
                st.push(temp);
                visited[temp] = ss - 1;
            }
            if(j + 1 < m && board[i][j + 1] == '.' && visited.find({i, j + 1}) == visited.end()) {
                board[i][j + 1] = ch;
                pair<int, int> temp = {i, j + 1};
                st.push(temp);
                visited[temp] = ss - 1;
            }
        }
        if(times > 1)
            canmove = true;
    }
    active[p] = newset;
    return canmove;
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> speed(p + 1);
    for(int i = 0; i < p; i++) {
        cin >> speed[i + 1];
    }
    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<set<pair<int, int> > > active(p + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] - '0' > 0 && board[i][j] - '0' < 10) {
                active[board[i][j] - '0'].insert({i, j});
            }
        }
    }
    bool possible = true;
    while(possible) {
        bool canmove = false;
        for(int i = 1; i <= p; i++) {
            canmove = turn(board, active, i, speed[i]) || canmove;
        }
        if(!canmove)
            possible = false;
    }
    vector<int> ans(p + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] - '0' > 0 && board[i][j] - '0' < 10)
                ans[board[i][j] - '0']++;
        }
    }
    for(int i = 1; i <= p; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
