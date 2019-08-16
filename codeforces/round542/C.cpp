#include <bits/stdc++.h>
using namespace std;



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


int euclidean(pair<int, int> p1, pair<int, int> p2) {
    int a = (p1.first - p2.first), b = (p1.second - p2.second);
    return a*a + b*b;
}

void dfs(set<pair<int, int> > &store, int i, int j, vector<vector<bool> > &visited, vector<string> &mat) {
    if(i == visited.size() || j == visited.size() || i < 0 || j < 0)
        return;
    if(visited[i][j] || mat[i][j] == '1')
        return;
    store.insert({i, j});
    visited[i][j] = true;
    dfs(store, i + 1, j, visited, mat);
    dfs(store, i - 1, j, visited, mat);
    dfs(store, i, j + 1, visited, mat);
    dfs(store, i, j - 1, visited, mat);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> src, dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;
    src.first--; src.second--;
    dest.first--; dest.second--;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    set<pair<int, int> > s1, s2;
    vector<vector<bool> > visited(n, vector<bool>(n, 0));
    dfs(s1, src.first, src.second, visited, mat);
    if(s1.find(dest) != s1.end()) {
        cout << 0 << endl;
        return 0;
    }
    dfs(s2, dest.first, dest.second, visited, mat);
    int mindist = INT_MAX;
    for(auto &p1 : s1) {
        for(auto &p2 : s2) {
            mindist = min(mindist, euclidean(p1, p2));
        }
    }
    cout << mindist << endl;
    return 0;
}
