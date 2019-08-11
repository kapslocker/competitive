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
    int capacity, minc = INT_MAX;
    cin >> capacity;
    char digit = '0';
    vector<int> cost(10);
    for(int i = 1; i < 10; i++) {
        cin >> cost[i];
        if(cost[i] <= minc) {
            minc = cost[i];
            digit = '0' + i;
        }
    }
    if(capacity < minc) {
        cout << -1 << endl;
        return 0;
    }
    int length = capacity / minc;
    string ans(length, digit);
    int rem = capacity - length * minc, s = 0, choice = digit - '0';
    int i = 9;
    while(i > choice) {
        if(cost[i] - cost[choice] <= rem) {
            ans[s++] = i + '0';
            rem = rem - (cost[i] - cost[choice]);
        }
        else {
            i--;
        }
    }
    cout << ans << endl;
    return 0;
}
