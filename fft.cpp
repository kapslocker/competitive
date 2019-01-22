#include <iostream>
#include <complex>
#include <vector>
using namespace std;

typedef complex<float> point;
const float pi = 3.14159;

void fft(vector<point> &fft_container, const vector<double> &coeffs, point root_n) {
    int n = coeffs.size();
    fft_container.resize(n);
    if(n == 1) {
        fft_container[0] = coeffs[0];
        return;
    }

    vector<double> coeffs_even, coeffs_odd;
    for(int i = 0; i < n; i++) {
        if(i%2 == 0)
            coeffs_even.push_back(coeffs[i]);
        else
            coeffs_odd.push_back(coeffs[i]);
    }
    vector<point> fft_container_even, fft_container_odd;
    fft(fft_container_even, coeffs_even, root_n * root_n);
    fft(fft_container_odd, coeffs_odd, root_n * root_n);

    point root(1.0);
    for(int k = 0; k < n / 2; k++) {
        fft_container[k] = fft_container_even[k] + root * fft_container_odd[k];
        fft_container[k + n/2] = fft_container_even[k] - root * fft_container_odd[k];
        root *= root_n;
    }
}


void multiply(vector<double> &ans, const vector<double> &coeffs_a, const vector<double> &coeffs_b) {
    // multiply two polynomials of equal degree n.
    assert(coeffs_a.size() == coeffs_b.size());
    vector<point> points_a, points_b;
    int n = coeffs_a.size();
    point root_n(cos(2*pi/n), sin(2*pi/n));
    fft(points_a, coeffs_a, root_n);
    fft(points_b, coeffs_b, root_n);
    vector<point>  points_c;
    for(int i = 0; i < n; i++) {
        points_c[i] = points_a[i] * points_b[i];
    }
    vector<double>  // TODO
}


int main() {
    /*
        Testing multiplication
        A(x) = 2 + 3*x +4*x*x
        B(x) = 1 + 6*x + 10*x*x
    */
    vector<int> ca = {2,3,4}, cb = {1,6,10};

    return 0;
}
