#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Function definition: f(x) = cos(x) - x*e^x
double f(double x) {
    return cos(x) - x * exp(x);
}

int main() {
   double x0 = 0.0, x1 = 1.0;   // Initial approximations
   double x2;
    int maxIter = 20;
  double tol = 1e-6;
   cout << "Secant Method\n";
   cout << "Function: f(x) = cos(x) - x*e^x\n";
   cout << "Initial approximations: x0 = " << x0 << ", x1 = " << x1 << "\n\n";
}
cout << fixed << setprecision(7);
cout << "Iteration\t x0\t\t x1\t\t x2\t\t f(x2)\n";
cout << "----------------------------------------------------------------\n";

  for (int i = 1; i <= maxIter; i++) {
     // Secant method formula: x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0))
      if (fabs(f(x1) - f(x0)) < tol) {
          cout << "Warning: Division by zero or very small denominator\n";
          break;
      }
    
      x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
      cout << i << "\t\t " << x0 << "\t " << x1 << "\t " << x2 << "\t " << f(x2) << "\n";

      // Check for convergence
      if (fabs(f(x2)) < tol) {
          cout << "\nRoot found at x = " << x2 << " after " << i << " iterations.\n";
          cout << "f(" << x2 << ") = " << f(x2) << endl;
          return 0;
            // Update approximations for next iteration     
              x0 = x1;      x1 = x2;
      }

  cout << "\nApproximate root after " << maxIter << " iterations: x = " << x2 << "\n";   
   cout << "f(" << x2 << ") = " << f(x2) << endl;
  return 0;
}
