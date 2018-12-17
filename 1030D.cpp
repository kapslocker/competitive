#include <complex>
#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = 4 * atan(1);
using namespace std;
long double distance(pair<long double, long double> a, pair<long double, long double>b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
        (a.second - b.second) * (a.second - b.second));
}

long double angle(long double d, long double r1, long double r2) {
    // double s = (d + r1 + r2) / 2.0;
    // double area = sqrt(s * (s - d));
    // area = area * sqrt((s - r1) * (s - r2));
//    return asin((2 * area)/ (d * r1));
    return acos( (d * d + r1 * r1 - r2 * r2)/ (2 * r1 * d));
}

int main() {
    pair<double, double> c1, c2;
    long double r1, r2;
    long double ans = 0;
    cin >> c1.first >> c1.second >> r1;
    cin >> c2.first >> c2.second >> r2;
    long double d = distance(c1, c2);
    if(d <= abs(r1 - r2)) {
        cout << setprecision(20) << pi * min(r1, r2) * min(r1, r2) << endl;
        return 0;
    }
    if(d > r1 + r2) {
        cout << 0 << endl;
        return 0;
    }
    long double the1 = angle(d, r1, r2), the2 = angle(d, r2, r1);
    ans = (the1 - sin(the1) * cos(the1)) * r1 * r1 + (the2 - sin(the2) * cos(the2)) * r2 * r2;
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
