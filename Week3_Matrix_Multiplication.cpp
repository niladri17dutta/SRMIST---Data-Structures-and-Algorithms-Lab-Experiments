#include <iostream>

using namespace std;

void inputMatrix(int matrix[2][2], const string &name) {
    cout << "Enter elements for matrix " << name << " (2x2):" << endl;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(int mat1[2][2], int mat2[2][2], int result[2][2]) {
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for(int k = 0; k < 2; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[2][2], const string &name) {
    cout << "Matrix " << name << " (2x2):" << endl;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat1[2][2], mat2[2][2], result[2][2];

    inputMatrix(mat1, "A");
    inputMatrix(mat2, "B");

    multiplyMatrices(mat1, mat2, result);

    cout << "Resultant Matrix C after multiplication:" << endl;
    printMatrix(result, "C");

    return 0;
}