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
    int a;
    string s;
    cin >> a >> s;
    int n = s.length();
    vector<int> arr(n + 1), pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        arr[i] = s[i - 1] - '0';
        pre[i] = arr[i] + pre[i - 1];
    }
    map<int, int> count;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int rsum = pre[i] - pre[j - 1];
            count[rsum]++;
        }
    }
    int ans = 0;
    if(a == 0) {
        int sum = 0;
        for(auto &p : count) {
            if(p.first != 0)
                sum += p.second;
        }
        cout << count[0] * (2 * sum + count[0]) << endl;
        return 0;
    }
    for(auto &p : count) {
        int key = p.first, val = p.second;
        if(key == 0 || (a % key != 0))
            continue;
        else {
            int rem = a / key;
            ans += val * count[rem];
        }
    }
    cout << ans << endl;
    return 0;
}
