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
    int n, k;
    cin >> n >> k;
    deque<int> q;
    vector<int> arr(n);
    map<int, int> present;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        // process arr[i]
        if(present[arr[i]] > 0) {
            // do nothing if present
            continue;
        }
        // if size < k, insert
        if(q.size() < k) {
            q.push_back(arr[i]);
            present[arr[i]] = q.size();
        }
        else {
            int id = q.front();
            q.pop_front();
            present[id] = 0;
            q.push_back(arr[i]);
            present[arr[i]] = q.size();
        }
    }
    cout << q.size() << endl;
    for(auto it = q.rbegin(); it < q.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
