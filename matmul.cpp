#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int k = A[0].size();

    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int x = 0; x < k; ++x) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> B = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    vector<vector<int>> C = multiplyMatrices(A, B);

    cout << "Resultant matrix:" << endl;
    printMatrix(C);

    return 0;
}
