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
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cout << 200000 << " " << 500 << endl;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,1e9); // distribution in range [1, 6]
    for(int i = 0; i < 200000; i++) {
        cout << dist6(rng) << " ";
    }
    cout << endl;
    return 0;
}