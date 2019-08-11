#include <iostream>
using namespace std;

int main(){
    int n, curr = 1, i;
    cin >> n;
    int a[n], d[n];
    for(i = 0; i < n; i++){
        cin >> a[i] >> d[i];
    }
    i = 0;
    while(i < n){
        int m = (curr - a[i]) / d[i] + 1;
        if(m <= 0)
            m = 1;
        if( a[i] + (m - 1) * d[i] >= curr){
            curr = a[i] + (m - 1) * d[i];
        }
        else{
            curr = a[i] + m * d[i];
        }
        i++;
        curr++;
    }
    cout << curr - 1 << endl;
    return 0;
}
