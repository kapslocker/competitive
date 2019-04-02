#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int solve(vector<int> &s, int n, int p) {
    sort(s.begin(), s.end());
    int req = 0, curr = 0;
    for(int i = 0; i < p; i++) {
        req += s[p - 1] - s[i];
    }
    curr = req;
    for(int i = p; i < n; i++) {
        curr -= s[i - 1] - s[i - p];
        curr += (s[i] - s[i - 1]) * (p - 1);
        if(curr < req)
            req = curr;
    }
    return req;
}

int32_t main() {
    int t;
    cin >> t;
    for(int j = 0; j < t; j++) {
        int n, p;
        cin >> n >> p;
        vector<int> s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        int ans = solve(s, n, p);
        cout << "Case #" << j + 1 << ": " << ans << endl;
    }
    return 0;
}
