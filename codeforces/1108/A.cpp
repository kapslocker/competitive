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

int c(char ch) {
    switch(ch) {
        case 'R':   return 0;
        case 'G':   return 1;
        case 'B':   return 2;
        default:    return 0;
    }
}
char r(int ch) {
    switch(ch) {
        case 0: return 'R';
        case 1: return 'G';
        case 2: return 'B';
        default: return 'R';
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = INT_MAX;
    cin >> n;
    string s, pat;
    cin >> s;
    vector<vector<int> > dp(n, vector<int>(3, INT_MAX));
    for(int j = 0; j < 3; j++) {
        dp[0][j] = (c(s[0]) != j);
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + (c(s[i]) != 0);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + (c(s[i]) != 1);
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + (c(s[i]) != 2);
    }
    ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    cout << ans << endl;
    string as;
    int curr;
    for(int j = 0; j < 3; j++) {
        if(dp[n - 1][j] == ans)
            curr = j;
    }
    for(int i = n - 1; i > 0; i--) {
        as += r(curr);
        int n = 0, v = INT_MAX;
        for(int j = 0; j < 3; j++) {
            if(j != curr && dp[i - 1][j] < v) {
                v = dp[i - 1][j];
                n = j;
            }
        }
        curr = n;
    }
    as += r(curr);
    reverse(as.begin(), as.end());
    cout << as << endl;
    return 0;
}
