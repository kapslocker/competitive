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

bool solve(int test_case) {
    int n;
    cin >> n;
    vector<pair<int, int> > activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].first >> activities[i].second;
    }
    set<pair<int, pair<int, int> > > events;
    vector<int> assignments(n, -1);
    // sort by time points
    // for equal time points, ends come before starts
    // for multiple ends at same point, end the earliest activity.
    for (int i = 0; i < n; i++) {
        events.insert({activities[i].first, {1, i}});
        events.insert({activities[i].second, {0, i}});
    }
    vector<bool> isFree(2, true);
    for (auto event: events) {
        int activity_id = event.second.second;
        int event_type = event.second.first;
        if (event_type == 1) {
            // assign to free person
            if (!isFree[0] && !isFree[1]) {
                return false;
            }
            if (isFree[0]) {
                assignments[activity_id] = 0;
                isFree[0] = false;
            }
            else {
                assignments[activity_id] = 1;
                isFree[1] = false;
            }
        }
        else {
            // free person assigned to this activity
            int assigned_person = assignments[activity_id];
            isFree[assigned_person] = 1;
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (assignments[i] == 0)
            ans.push_back('C');
        else
            ans.push_back('J');
    }
    cout << "Case #" << test_case << ": " << ans << endl;
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        bool ans = solve(c);
        if (!ans) {
            cout << "Case #" << c << ": " << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
