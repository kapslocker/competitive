#include <bits/stdc++.h>
using namespace std;


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

void solve(int c) {
    string str;
    cin >> str;
    int curr_open = 0;
    string ans;
    for (int i = 0; i < str.length(); i++) {
        int digit = str[i] - '0'; 
        int open_count = max(digit - curr_open, 0);
        int closed_count = max(curr_open - digit, 0);
        curr_open += open_count - closed_count;
        ans.append(string(open_count, '('));
        ans.append(string(closed_count, ')'));
        ans.push_back(digit + '0');
    }
    ans.append(string(curr_open, ')'));
    cout << "Case #" << c << ": " << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
