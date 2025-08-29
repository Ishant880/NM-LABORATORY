#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function definition: f(x) = x^3 + 3x^2 - 1
double f(double x) {
    return x*x*x + 3*x*x - 1;
}

int main() {
    double x1 = -3.0, x2 = -2.0;   // Initial approximations
    double x3;
    int maxIter = 20;
    double tol = 1e-4;

    cout << "Secant Method\n";
    cout << "Function: f(x) = x^3 + 3x^2 - 1\n";
    cout << "Initial approximations: x1 = " << x1 << ", x2 = " << x2 << "\n";
    cout << "Error tolerance: " << tol << "\n\n";

    cout << fixed << setprecision(7);
    cout << "Iteration\t x1\t\t x2\t\t x3\t\t f(x3)\n";
    cout << "----------------------------------------------------------------\n";

    for (int i = 1; i <= maxIter; i++) {
        // Secant method formula: x3 = x2 - f(x2)*(x2 - x1)/(f(x2) - f(x1))
        if (fabs(f(x2) - f(x1)) < tol) {
            cout << "Warning: Division by zero or very small denominator\n";
            break;
        }
        
        x3 = x2 - f(x2) * (x2 - x1) / (f(x2) - f(x1));

        cout << i << "\t\t " << x1 << "\t " << x2 << "\t " << x3 << "\t " << f(x3) << "\n";

        // Check for convergence
        if (fabs(f(x3)) < tol) {
            cout << "\nRoot found at x = " << x3 << " after " << i << " iterations.\n";
            cout << "f(" << x3 << ") = " << f(x3) << endl;
            return 0;
        }

        // Update approximations for next iteration
        x1 = x2;
        x2 = x3;
    }

    cout << "\nApproximate root after " << maxIter << " iterations: x = " << x3 << "\n";
    cout << "f(" << x3 << ") = " << f(x3) << endl;

    return 0;
}
