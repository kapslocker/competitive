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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stack<int> st;
    vector<vector<int> > l(2, vector<int>(n, 0)), r(2, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if(st.empty())
            l[0][i] = -1;
        else
            l[0][i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(st.empty())
            r[0][i] = n;
        else
            r[0][i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(st.empty())
            l[1][i] = -1;
        else
            l[1][i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if(st.empty())
            r[1][i] = n;
        else
            r[1][i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    int ans = 0;
    vector<int> pos(n), neg(n);
    for(int i = 0; i < n; i++) {
        int a = (i - l[0][i]) * (r[0][i] - i);
        int b = (i - l[1][i]) * (r[1][i] - i);
        pos[i] = a * arr[i];
        neg[i] = b * arr[i];
        ans += pos[i] - neg[i];
    }
    cout << ans << endl;
    return 0;
}
