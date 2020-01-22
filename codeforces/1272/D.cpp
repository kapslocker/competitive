#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int> > dp(n, vector<int>(2, 1));
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(n == 2) {
        cout << (arr[0] < arr[1] ? 2 : 1) << endl;
        return 0;
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] = arr[i] > arr[i-1] ? dp[i-1][0] + 1 : 1;
    }
    for(int i = 2; i < n; i++) {
        if(arr[i] > arr[i-2]) {
            dp[i][1] = max(dp[i][1], dp[i-2][0] + 1);
        }
        if(arr[i] > arr[i-1]) {
            dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans << endl;
    return 0;
}
