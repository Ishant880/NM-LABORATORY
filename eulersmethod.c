#include <stdio.h>

// Define the function f(x, y) = dy/dx
double f(double x, double y) {
    return -2 * x * y * y;
}

int main() {
    double x0, y0, xn, h, yn, slope;
    int n, i;

    // Input initial values from user
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter value of x at which y is required (xn): ");
    scanf("%lf", &xn);
    printf("Enter step size (h): ");
    scanf("%lf", &h);

    // Calculate number of steps
    n = (int)((xn - x0) / h);

    printf("\nStep\tx\t\ty\t\tslope=f(x,y)\n");
    printf("---------------------------------------------\n");

    // Euler’s method iteration
    for(i = 0; i < n; i++) {
        slope = f(x0, y0);
        yn = y0 + h * slope;
        printf("%d\t%.4lf\t%.6lf\t%.6lf\n", i+1, x0, y0, slope);
        x0 = x0 + h;
        y0 = yn;
    }

    printf("\nApproximate value of y at x = %.2lf is %.6lf\n", xn, y0);

    return 0;
}
