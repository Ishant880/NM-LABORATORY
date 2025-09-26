#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to perform partial pivoting
void partialPivot(vector<vector<double>>& a, vector<double>& b, int n, int k) {
    int maxRow = k;
    double maxVal = fabs(a[k][k]);
    for (int i = k + 1; i < n; ++i) {
        if (fabs(a[i][k]) > maxVal) {
            maxVal = fabs(a[i][k]);
            maxRow = i;
        }
    }
    if (maxRow != k) {
        swap(a[k], a[maxRow]);
        swap(b[k], b[maxRow]);
    }
}

// Function to perform Gauss Elimination with partial pivoting
vector<double> gaussElimination(vector<vector<double>> a, vector<double> b, int n) {
    for (int k = 0; k < n - 1; ++k) {
        partialPivot(a, b, n, k);
        for (int i = k + 1; i < n; ++i) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j < n; ++j) {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    return x;
}

void printSolution(const vector<double>& x) {
    cout << fixed << setprecision(6);
    for (size_t i = 0; i < x.size(); ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    // First test problem (4x4)
    vector<vector<double>> a1 = {
        {1, 3, 3, 4},
        {2, 6, 5, -4},
        {3, 7, 2, 2},
        {2, 3, 5, 6}
    };
    vector<double> b1 = {4, 3, 12, 5};

    cout << "Solution for the 4x4 system:" << endl;
    vector<double> x1 = gaussElimination(a1, b1, 4);
    printSolution(x1);

    // Second test problem (3x3)
    vector<vector<double>> a2 = {
        {4, 1, 2},
        {2, 4, -1},
        {1, 1, -3}
    };
    vector<double> b2 = {9, -5, -9};

    cout << "\nSolution for the 3x3 system:" << endl;
    vector<double> x2 = gaussElimination(a2, b2, 3);
    printSolution(x2);

    return 0;
}
