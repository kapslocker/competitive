#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 2e5 + 1;
long long int multx(int x, vector<int> &arr){
    if(x > MAX / 2)
        return x;
    long long int ans = 0;
    int i = 1;
    while(i * x <= MAX){
        ans += (arr[min((i + 1) * x, MAX)] - arr[i * x] ) * i * x;
        i++;
    }
    return ans;
}
int main() {
    int n, i;
    scanf("%d\n", &n);
    vector<int> a(n);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(), a.end());
    vector<int> pre(MAX + 1, 0);
    int j = 0, curr = 0;
    i = 1;
    while(i <= MAX && j <= n){
        if(j < n && a[j] < i){
            curr++;
            j++;
        }
        else{
            pre[i] = pre[i - 1] + curr;
            curr = 0;
            i++;
        }
    }
    long long int maxans = 0;
    for(i = 0; i < n; i++){
        long long int currans = multx(a[i], pre);
        if(currans > maxans)
            maxans = currans;
    }
    printf("%lld\n", maxans);
    return 0;
}
