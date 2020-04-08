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

int query(int pos) {
    cout << pos + 1<< endl;
    int val;
    cin >> val;
    return val;
}

void print(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}

void reverse(vector<int> &ans) {
    int n = ans.size();
    for (int i = 0; i < n / 2; i++) {
        swap(ans[i], ans[n-1-i]);
    }
}

void complement(vector<int> &ans) {
    int n = ans.size();
    for (int i = 0; i < n; i++) {
        ans[i] = !ans[i];
    }
}

void complementandreverse(vector<int> &ans) {
    complement(ans);
    reverse(ans);
}

void solve(int n) {
    vector<int> ans(n, 0);
    bool pairs_found = false;
    pair<int, int> pair_locs = {0, -1};
    int queries_done = 0;
    int i = 0;
    while (i <= n / 2) {
        if (queries_done && queries_done % 10 == 0) {
            // 2 special queries.
            debug(ans, i);
            debug(pair_locs);
            if (pairs_found == true) {
                // query for pairs and rebalance
                int a = query(pair_locs.first), b = query(pair_locs.second);
                if ((ans[pair_locs.first] == a) && (b = ans[pair_locs.second])) {
                    // no change
                }
                else if ((a != ans[pair_locs.first]) && (b == ans[pair_locs.second])) {
                    complementandreverse(ans);
                }
                else if ((a != ans[pair_locs.first]) && (b != ans[pair_locs.second])) {
                    complement(ans);
                }
                else {
                    reverse(ans);
                }
                queries_done += 2;
            }
            else {
                // imitate what happened to the first index
                int new_val = query(0);
                new_val = query(0);
                if (new_val != ans[0]) {
                    complement(ans);
                }
                queries_done += 2;
            }
        }
        else {
            while(queries_done == 0 || queries_done % 10 != 0) {
                // cerr << i << " " << n - 1 - i << " " << queries_done << endl;
                ans[i] = query(i);
                ans[n-1-i] = query(n-1-i);
                int a = ans[0] == ans[n-1], b = ans[i] == ans[n-1-i];
                i++;
                queries_done += 2;
                if (pairs_found)
                    continue;
                if ((!a && b) || (a && !b)) {
                    pairs_found = true;
                    if (a) {
                        pair_locs.first = 0;
                        pair_locs.second = i - 1;
                    }
                    else {
                        pair_locs.first = i - 1;
                        pair_locs.second = 0;
                    }
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        cout << ans[j];
    }
    cout << endl;
    char ch;
    cin >> ch;
    if (ch == 'N')
        exit(0);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    int b;
    cin >> b;
    for (int i = 0; i < t; i++) {
        solve(b);
    }
    return 0;
}
