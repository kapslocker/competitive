#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e8;

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

vector<vector<int> > rev_graph;
vector<int> order;
vector<bool> isinserted(501, false);
void dijkstra(vector<vector<int> > &graph, vector<vector<int> > &dist, int v, bool isrev) {
    int n = graph.size() - 1;
    set<pair<int, int> > vertices;
    dist[v][v] = 0;
    for(int i = 1; i <= n; i++) {
        if(!isinserted[i])
            continue;
        if(isrev)
            vertices.insert({dist[i][v], i});
        else
            vertices.insert({dist[v][i], i});
    }
    while(!vertices.empty()) {
        pair<int, int> p = *vertices.begin();
        vertices.erase(vertices.begin());
        int currdist = p.first, src = p.second;
        int temp;
        for(int i = 1; i <= n; i++) {
            if(graph[src][i] == 0 || !isinserted[i])
                continue;
            if(isrev)
                temp = dist[i][v];
            else
                temp = dist[v][i];
            if(temp > currdist + graph[src][i]) {
                vertices.erase(vertices.find({temp, i}));
                temp = currdist + graph[src][i];
                vertices.insert({temp, i});
                if(isrev)
                    dist[i][v] = temp;
                else
                    dist[v][i] = temp;
            }
        }
    }
}

void updatedist(vector<vector<int> > &graph, vector<vector<int> > &dist, int v) {
    int n = graph.size() - 1;
    dijkstra(graph, dist, v, false);
    dijkstra(rev_graph, dist, v, true);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
        }
    }
}

long long int evalsum(vector<vector<int> > &dist) {
    int n = dist.size() - 1;
    long long int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] < 1e8)
                sum += dist[i][j];
        }
    }
    return sum;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, MAX));
    rev_graph.resize(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            rev_graph[j][i] = graph[i][j];
        }
    }
    order.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> order[i];
    }
    reverse(order.begin(), order.end());
    vector<long long int> ans;
    for(int v : order) {
        isinserted[v] = true;
        updatedist(graph, dist, v);
        ans.push_back(evalsum(dist));
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
