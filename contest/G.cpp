#include <bits/stdc++.h>

using namespace std;

int remainder(vector<int> &a, int rem) {
    vector<int> temp = a;
    for(int i = 0; i < 7; i++)
        temp.push_back(a[i]);
    int ans = INT_MAX;
    for(int i = 0; i < 14; i++) {
        for(int j = i; j < 14; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++)
                sum += temp[k];
            if(sum == rem && (j - i + 1) < ans)
                ans = j - i + 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k, found = false, start, times, count = 0, ans = 0;
        cin >> k;
        vector<int> a(7);
        for(int i = 0; i < 7; i++) {
            cin >> a[i];
            if(a[i]) {
                count++;
                if(!found) {
                    start = i;
                    found = true;
                }
            }
        }
        int weeks = k % count == 0 ? (k/count - 1) : k / count;
        ans += 7 * weeks;
        k = k - count * weeks;
        ans += remainder(a, k);
        cout << ans << endl;
    }
    return 0;
}
