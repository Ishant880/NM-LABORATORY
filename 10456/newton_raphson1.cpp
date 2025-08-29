#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function definition: f(x) = x * e^x - 1
double f(double x) {
    return x * exp(x) - 1;
}

// Derivative of f(x): f'(x) = e^x + x * e^x = e^x * (1 + x)
double df(double x) {
    return exp(x) * (1 + x);
}

int main() {
    double x0 = 0.5;   // Initial approximation
    double x1;
    int maxIter = 10;
    double tol = 1e-6;

    cout << "Newton-Raphson Method\n";
    cout << "Function: f(x) = x * e^x - 1\n";
    cout << "Derivative: f'(x) = e^x * (1 + x)\n";
    cout << "Initial approximation: x0 = " << x0 << "\n";
    cout << "Max iterations: " << maxIter << "\n\n";

    cout << fixed << setprecision(7);
    cout << "Iteration\t x0\t\t f(x0)\t\t f'(x0)\t\t x1\t\t f(x1)\n";
    cout << "----------------------------------------------------------------\n";

    for (int i = 1; i <= maxIter; i++) {
        if (fabs(df(x0)) < tol) {
            cout << "Warning: Derivative is zero or very small\n";
            break;
        }

        x1 = x0 - f(x0) / df(x0);

        cout << i << "\t\t " << x0 << "\t " << f(x0) << "\t " << df(x0) << "\t " << x1 << "\t " << f(x1) << "\n";

        if (fabs(f(x1)) < tol) {
            cout << "\nRoot found at x = " << x1 << " after " << i << " iterations.\n";
            cout << "f(" << x1 << ") = " << f(x1) << endl;
            return 0;
        }

        x0 = x1;
    }

    cout << "\nApproximate root after " << maxIter << " iterations: x = " << x1 << "\n";
    cout << "f(" << x1 << ") = " << f(x1) << endl;

    return 0;
}
