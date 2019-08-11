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

bool check(vector<vector<bool> > &grid, int a, int b, int c, int d) {
    for(int i = a; i <= c; i++) {
        for(int j = b; j <= d; j++) {
            if(grid[i][j])
                return false;
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool> > grid(n + 1, vector<bool>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) {
            if(s[j-1] == '1')
                grid[i][j] = 1;
        }
    }
    vector<vector<int> > pre(n+1, vector<int>(m+1, 0)), row(m+1, vector<int>(n+1));
    vector<vector<int> > calc(n + 1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= i; k++) {
                for(int l = 1; l <= j; l++) {
                    calc[i][j] += check(grid, k, l, i, j);
                }
            }
        }
    }
    debug(calc);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = pre[i][j - 1] + pre[i-1][j] - pre[i-1][j-1] + calc[i][j];
        }
    }
    debug(pre);
    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pre[c][d] - pre[c][b-1] - pre[a-1][d] + pre[a-1][b-1] << "\n";
    }
    cout << endl;
    return 0;
}