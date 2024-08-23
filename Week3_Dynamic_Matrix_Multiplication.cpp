#include <iostream>

using namespace std;

void inputMatrix(int** matrix, const string& name) {
    cout << "Enter elements for matrix " << name << " (2x2):" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(int** mat1, int** mat2, int** result) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int** matrix, const string& name) {
    cout << "Matrix " << name << " (2x2):" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int** mat1 = new int*[2];
    int** mat2 = new int*[2];
    int** result = new int*[2];

    for (int i = 0; i < 2; ++i) {
        mat1[i] = new int[2];
        mat2[i] = new int[2];
        result[i] = new int[2];
    }

    inputMatrix(mat1, "A");
    inputMatrix(mat2, "B");
    multiplyMatrices(mat1, mat2, result);
    cout << "Resultant Matrix C after multiplication:" << endl;
    printMatrix(result, "C");

    for (int i = 0; i < 2; ++i) {
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] result[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] result;

    return 0;
}
