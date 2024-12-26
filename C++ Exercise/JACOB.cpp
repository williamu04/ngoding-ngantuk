#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// Define the Jacobi Iteration function
void jacobiIteration(const vector<vector<double>>& A, const vector<double>& b, double tolerance) {
    int n = A.size(); // Number of equations
    vector<double> x(n, 0.0); // Initial guess for solution
    vector<double> x_new(n, 0.0); // Updated solution
    double error;

    cout << "Enter tolerable error: ";
    cin >> tolerance;

    do {
        error = 0.0;

        // Perform Jacobi iteration
        for (int i = 0; i < n; ++i) {
            x_new[i] = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];

            // Calculate error
            error = max(error, fabs(x_new[i] - x[i]));

            // Update solution for next iteration
            x[i] = x_new[i];
        }
    } while (error > tolerance);

    // Display the solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

int main() {
    int n; // Number of equations
    double tolerance;

    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter the coefficients of the equations (matrix A):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants (vector b):\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    jacobiIteration(A, b, tolerance);

    return 0;
}
