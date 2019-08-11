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
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = 0; i < n; i++) {
        arr.push_back(arr[i]);
    }
    n = 2 * n;
    debug(arr);
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] <= arr[i]) {
                if(dp[j] + 1 > dp[i]) {
                    prev[i] = j;
                    dp[i] = dp[j] + 1;
                }
                else if(dp[j] + 1 == dp[i]) {
                    if(freq[arr[prev[i]]] < freq[arr[j]]) {
                        prev[i] = j;
                    }
                }
            }
        }
    }
    int m = INT_MIN, idx = -1;
    for(int i = 0; i < n; i++) {
        if(dp[i] > m) {
            m = dp[i];
            idx = i;
        }
    }
    set<int> nums;
    while(idx != -1) {
        nums.insert(arr[idx]);
        idx = prev[idx];
    }
    int ans = 0;
    m = INT_MIN;
    for(int x : nums) {
        m = max(m, freq[x]);
    }
    for(int i = 0; i < n / 2; i++) {
        if(nums.find(arr[i]) != nums.end()) {
            ans++;
        }
    }
    ans += m * (t - 1);
    cout << ans << endl;
    return 0;
}
