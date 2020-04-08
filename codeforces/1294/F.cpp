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

pair<int, int> farthest(map<int, vector<int> > &graph, int s, vector<bool> &visited) {
    visited[s] = true;
    int maxdepth = 0, f = s;
    for (int x : graph[s]) {
        if(visited[x])
            continue;
        auto u = farthest(graph, x, visited);
        if (u.second > maxdepth) {
            maxdepth = u.second;
            f = u.first;
        }
    }
    return {f, 1 + maxdepth};
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<int> > graph;
    vector<pair<int, int> > edges;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int s = 1, end1 = -1, maxdist = 0, end2 = -1;
    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;
    stack<int> st;
    st.push(s);
    vector<bool> visited(n + 1, false);
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        visited[u] = true;
        for(int x : graph[u]) {
            if(visited[x])
                continue;
            dist[x] = dist[u] + 1;
            st.push(x);
            if (dist[x] >  maxdist) {
                maxdist = dist[x];
                end1 = x;
            }
        }
    }
    // found end 1 of diameter
    st.push(end1);
    visited.assign(n + 1, false);
    maxdist = 0;
    dist.assign(n+1, INT_MAX);
    dist[end1] = 0;
    vector<int> parent(n+1, -1);
    parent[end1] = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        visited[u] = true;
        for(int x : graph[u]) {
            if(visited[x])
                continue;
            parent[x] = u;
            dist[x] = dist[u] + 1;
            st.push(x);
            if (dist[x] >  maxdist) {
                maxdist = dist[x];
                end2 = x;
            }
        }
    }
    // found end2 of diameter
    // break graph
    map<int, vector<int> > g2;
    set<int> origins;
    int t1 = end2;
    while(parent[t1] > 0) {
        if (t1 != end2)
            origins.insert(t1);
        t1 = parent[t1];
    }
    visited.assign(n+1, false);
    for (pair<int, int> x :  edges) {
        int u = x.first;
        int v = x.second;
        if (origins.find(u) != origins.end() && origins.find(v) !=  origins.end() ) {
            continue;
        }
        else {
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
    }
    int end3, maxdepth = 0;
    int ans = dist[end2];
    visited[end1] = true;
    visited[end2] = true;
    for(int sta : origins) {
        pair<int, int> temp = farthest(g2, sta, visited);
        if (temp.second > maxdepth) {
            maxdepth = temp.second;
            end3 = temp.first;
        }
    }
    cout << ans + maxdepth - 1 << endl;
    cout << end1 << " " << end2 << " " <<  end3 << endl;
    return 0;
}
