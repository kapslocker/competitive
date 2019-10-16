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

int hash_vector(vector<int> &vec) {
  size_t seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int n, s;
        cin >> n >> s;
        // unordered_map<int, vector<int> > category;
        // for(int i = 1; i <= n; i++) {
        //     int c;
        //     cin >> c;
        //     vector<int> choices(c);
        //     for(int j = 0; j < c; j++) {
        //         cin >> choices[i];
        //     }
        //     sort(choices.begin(), choices.end());
        //     int val = hash_vector(choices);
        //     category[val].push_back(i);
        // }
        // // edges exist between people of different categories
        unordered_map<int, vector<int> > graph;
        vector<unordered_set<int> > skills(n);
        for(int i = 0; i < n; i++) {
            int c, x;
            cin >> c;
            for(int j = 0; j < c; j++) {
                cin >> x;
                skills[i].insert(x);
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(auto &x : skills[i]) {
                    if(skills[j].find(x) == skills[j].end()) {
                        count++;
                        break;
                    }
                }
            }
        }
        cout << "Case #" << tt << ": " << count << endl;
    }
    return 0;
}
