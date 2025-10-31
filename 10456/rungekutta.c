#include <stdio.h>
#include <math.h>

// Function definition for dy/dx = f(x, y)
double f(double x, double y) {
    return sqrt(x + y);
}

int main() {
    double x0, y0, h, xn;
    double k1, k2, k3, k4, yn;
    int steps;

    // Taking inputs from user
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);

    printf("Enter step size (h): ");
    scanf("%lf", &h);

    printf("Enter final value of x (xn): ");
    scanf("%lf", &xn);

    // Calculate number of steps
    steps = (int)((xn - x0) / h);

    printf("\nStep-by-step Runge-Kutta Calculation:\n");
    printf("x\t\ty\n");
    printf("%.4lf\t%.6lf\n", x0, y0);

    for (int i = 0; i < steps; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2.0, y0 + k1 / 2.0);
        k3 = h * f(x0 + h / 2.0, y0 + k2 / 2.0);
        k4 = h * f(x0 + h, y0 + k3);

        yn = y0 + (1.0 / 6.0) * (k1 + 2*k2 + 2*k3 + k4);
        x0 = x0 + h;
        y0 = yn;

        printf("%.4lf\t%.6lf\n", x0, y0);
    }

    printf("\nApproximate value of y(%.2lf) = %.6lf\n", xn, yn);

    return 0;
}
