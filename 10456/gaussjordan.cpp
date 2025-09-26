#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;

void printMatrix(double mat[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << setw(10) << mat[i][j] << " ";
        cout << endl;
    }
}

void gaussJordanInverse(double a[N][N], double inv[N][N]) {
    // Initialize inv as identity matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            inv[i][j] = (i == j) ? 1.0 : 0.0;

    for (int i = 0; i < N; ++i) {
        // Find the pivot
        double pivot = a[i][i];
        if (pivot == 0) {
            // Search for a non-zero pivot and swap rows
            for (int k = i + 1; k < N; ++k) {
                if (a[k][i] != 0) {
                    for (int j = 0; j < N; ++j) {
                        swap(a[i][j], a[k][j]);
                        swap(inv[i][j], inv[k][j]);
                    }
                    pivot = a[i][i];
                    break;
                }
            }
        }
        if (pivot == 0) {
            cout << "Matrix is singular and cannot be inverted." << endl;
            return;
        }

        // Normalize the pivot row
        for (int j = 0; j < N; ++j) {
            a[i][j] /= pivot;
            inv[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < N; ++k) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j < N; ++j) {
                    a[k][j] -= factor * a[i][j];
                    inv[k][j] -= factor * inv[i][j];
                }
            }
        }
    }
}

int main() {
    // Coefficient matrix for the system:
    // x - y + z = 0
    // 2x + y - 3z = 4
    // x + y + z = 1
    double a[N][N] = {
        {1, -1, 1},
        {2, 1, -3},
        {1, 1, 1}
    };
    double inv[N][N];

    gaussJordanInverse(a, inv);

    cout << "Inverse of the coefficient matrix:" << endl;
    printMatrix(inv);

    return 0;
}
