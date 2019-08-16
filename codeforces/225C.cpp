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



int solve(vector<vector<int> > &costs, int m, int x, int y) {
    vector<vector<int> > dp(m + 1, vector<int>(2, 0));
    for(int i  = m - 1; i >= 0; i--) {
        for(int c = 0; c < 2; c++) {
            int minv = INT_MAX;
            for(int j = i + x - 1; j <= min(i + y - 1, m - 1); j++) {
                minv = min(dp[j + 1][1 ^ c] + costs[i][c] - costs[j + 1][c], minv);
            }
            dp[i][c] = minv;
        }
    }
    // debug(dp, costs);
    cout << min(dp[0][0], dp[0][1]) << endl;
}

int32_t main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int, int> > arr(m, {0, 0});
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.')
                arr[j].first++;
            else
                arr[j].second++;
        }
    }
    vector<vector<int> > suf(m + 1, {0, 0});
    suf[m - 1][0] = arr[m - 1].second;
    suf[m - 1][1] = arr[m - 1].first;
    for(int i = m - 2; i >= 0; i--) {
        suf[i][0] = suf[i + 1][0] + arr[i].second;
        suf[i][1] = suf[i + 1][1] + arr[i].first;
    }
    solve(suf, m, x, y);
    return 0;
}
