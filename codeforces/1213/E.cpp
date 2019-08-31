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
    string s, t;
    string test="abc";
    cin >> n >> s >> t;
    vector<string> perms;
    perms.push_back(test);
    while(next_permutation(test.begin(), test.end())) {
        perms.push_back(test);
    }
    for(string x : perms) {
        string ans1;
        for(int i = 0; i < n; i++)
            ans1 += x;
        if(ans1.find(s) == string::npos && ans1.find(t) == string::npos) {
            cout << "YES\n";
            cout << ans1 << endl;
            return 0;
        }
        string ans2 = string(n, ans1[0]) + string(n, ans1[1]) + string(n, ans1[2]);
        if(ans2.find(s) == string::npos && ans2.find(t) == string::npos) {
            cout << "YES\n";
            cout << ans2 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
