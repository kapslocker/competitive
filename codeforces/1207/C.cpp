#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e18;

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

int solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> dp(n+1, vector<int>(2, MAX));
    dp[0][0] = b;
    dp[0][1] = MAX;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '1') {
            dp[i-1][0] = MAX;
        }
        // either continue up
        dp[i][1] = min(dp[i][1], dp[i-1][1] + a + b + b);
        // fall down
        dp[i][0] = min(dp[i][0], dp[i-1][1] + a + a + b);
        // continue down
        dp[i][0] = min(dp[i][0], dp[i-1][0] + a + b);
        // rise up
        dp[i][1] = min(dp[i][1], dp[i-1][0] + a + a + b + b);
        if(s[i-1] == '1') {
            dp[i][0] = MAX;
        }
        
    }
    // for(int i = 0; i <= n; i++) {
    //     debug(i, dp[i]);
    // }
    return dp[n][0];
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}
