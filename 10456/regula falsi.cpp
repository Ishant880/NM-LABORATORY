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

    cout << "Regula Falsi (False Position) Method\n";
    cout << "Function: f(x) = cos(x) - x*e^x\n";
    cout << "Interval: [" << a << ", " << b << "]\n\n";

    if (f(a) * f(b) >= 0) {
        cout << "Regula Falsi method not applicable: f(a) and f(b) must have opposite signs.\n";
        cout << "f(" << a << ") = " << f(a) << ", f(" << b << ") = " << f(b) << endl;
        return 0;
    }

    cout << fixed << setprecision(7);
    cout << "Iteration\t a\t\t b\t\t c\t\t f(c)\n";
    cout << "----------------------------------------------------------------\n";

    for (int i = 1; i <= maxIter; i++) {
        // Regula Falsi formula: c = (a*f(b) - b*f(a)) / (f(b) - f(a))
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << i << "\t\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << "\n";

        // Check for convergence
        if (fabs(f(c)) < tol) {
            cout << "\nRoot found at x = " << c << " after " << i << " iterations.\n";
            cout << "f(" << c << ") = " << f(c) << endl;
            return 0;
        }

        // Update interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nApproximate root after " << maxIter << " iterations: x = " << c << "\n";
    cout << "f(" << c << ") = " << f(c) << endl;

    return 0;
}
