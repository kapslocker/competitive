#include <bits/stdc++.h>

using namespace std;

int getans(int query) {
    int ans;
    cout << query << endl;
    fflush(stdout);
    cin >> ans;
    return ans;
}
void binsearch(int low, int high, vector<int> &truth) {
    int mid, n = truth.size(), i = 0, ans;
    while(low < high) {
        mid = (low + high) / 2;
        ans = truth[i] * getans(mid);
        i = (i + 1) % n;
        if(ans == 0) {
            return;
        }
        if(ans > 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    getans(low);
}

int main() {
    int m, n, ans;
    cin >> m >> n;
    vector<int> p(n);
    int i;
    for(i = 0; i < n; i++) {
        ans = getans(i + 1);
        if(ans == 0)
            return 0;
        if(ans == 1) {
            p[i] = 1;
        }
        else if(ans == -1) {
            p[i] = -1;
        }
    }
    binsearch(1, m, p);
    return 0;
}
