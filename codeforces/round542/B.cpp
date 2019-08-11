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
    cin >> n;
    vector<int> arr(2 * n);
    map<int, vector<int> > pos;
    for(int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    int cs = 0, cd = 0, count = 0, dist = 0;
    while(count < n) {
        int curr = count + 1;
        int pa = pos[curr][0], pb = pos[curr][1];
        int d1 = abs(cs - pa) + abs(cd - pb);
        int d2 = abs(cs - pb) + abs(cd - pa);
        if(d1 <= d2) {
            cs = pa;
            cd = pb;
        }
        else {
            cs = pb;
            cd = pa;
        }
        dist += min(d1, d2);
        count++;
    }
    cout << dist << endl;
    return 0;
}
