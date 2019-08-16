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
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int > > graph(n, vector<int>(n, 0));
    unordered_map<int, vector<int> > g2;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        graph[a][b] = 1;
        g2[a].push_back(b);
    }
    int ans = 0;
    for(int a = 0; a < n; a++) {
        for(int c = 0; c < n; c++) {
            if(a != c) {
                int count = 0;
                for(auto &p : g2[a]) {
                    if(graph[p][c])
                        count++;
                }
                ans += (count * (count - 1)) / 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
