#include <bits/stdc++.h>
using namespace std;

// #define int long long


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


map<string, int> dp;
int solve(string s, vector<int> &reward) {
    int n = s.length();
    if(s.length() == 1)
        return reward[0];
    if(dp.find(s) != dp.end())
        return dp[s];
    vector<vector<int> > pre(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        pre[i][0] = i > 0 ? pre[i - 1][0] : 0;
        pre[i][1] = i > 0 ? pre[i - 1][1] : 0;
        pre[i][0] += (s[i] == '0');
        pre[i][1] += (s[i] == '1');
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(pre[i][0] == pre[j + 1][0] || pre[i][1] == pre[j + 1][1]) {
                ans = max(ans, reward[i - j - 1] + solve(s.substr(0, j + 1) + s.substr(i + 1), reward));
            }
        }
    }
    dp[s] = ans;
    return ans;
}
int32_t main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(s, a) << endl;
    return 0;
}
