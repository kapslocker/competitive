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
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, INT_MAX));
    for(int i = 0; i < n; i++) {
        dp[n][i] = 0;
        dp[i][n] = 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i > j) {
                dp[i][j] = 0;
                continue;
            }
            if(i == j) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
            for(int k = i + 2; k <= j; k++) {
                if(arr[i] == arr[k]) {
                    dp[i][j] = min(dp[i + 1][k - 1] + dp[k + 1][j], dp[i][j]);
                }
            }
            if(arr[i] == arr[i + 1]) {
                dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
