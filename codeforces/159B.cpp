#include <bits/stdc++.h>

using namespace std;


int main() {
    long long int n, a, b, x, vx, vy, g, ans = 0;
    cin >> n >> a >> b;
    unordered_map<long long int, int> hmap;
    unordered_map<long long int, unordered_map<long long int, int> > slopes;
    for(int i = 0; i < n; i++) {
        cin >> x >> vx >>  vy;
        ans += hmap[a * vx - vy] - slopes[vx][vy];
        hmap[a * vx - vy]++;
        slopes[vx][vy]++;
    }
    cout << 2 * ans << endl;
    return 0;
}
