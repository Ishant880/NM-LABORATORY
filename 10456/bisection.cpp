
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function definition: f(x) = cos(x) - x*e^x
double f(double x) {
    return cos(x) - x * exp(x);
}

int main() {
    double a = 0.0, b = 1.0;   // interval (0,1)
    double c;
    int maxIter = 20;
    double tol = 1e-6;

    if (f(a) * f(b) >= 0) {
        cout << "Bisection method not applicable: f(a) and f(b) must have opposite signs.\n";
        return 0;
    }

    cout << fixed << setprecision(7);
    cout << "Iteration\t a\t\t b\t\t c\t\t f(c)\n";

    for (int i = 1; i <= maxIter; i++) {
        c = (a + b) / 2.0;

        cout << i << "\t\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << "\n";

        if (fabs(f(c)) < tol || (b - a) / 2 < tol) {
            cout << "\nRoot found at x = " << c << " after " << i << " iterations.\n";
            return 0;
        }

        // Update interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nApproximate root after " << maxIter << " iterations: x = " << c << "\n";

    return 0;
}



